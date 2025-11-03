///////////////////////////////////////////////////////////////////////////////////////
// This script does many thigsat the same time
// Main function of the script is fadcScintDataProcess (at the very bottom)
// Pass the arguments to the script in the following order:
//      - FadcScintDataProcess("filename.root", "trename", howmanyevents, whichchannel)
//      - Eg: FadcScintDataProcess("pion_det_fadc_replayed_177_seg0_1.root", "T", 2, 4)
//
// There are three other helper functions:
//      - GetChannelData - get data for specified channel and events
//      - PlotWaveForms - plot waveforms for specified channel and events
//      - PrintRawData - print rawdata for specified channel and events
//                     - this is commented in the main function temporary
//
// Enjoy!!
//
///////////////////////////////////////////////////////////////////////////////////////

# include <iostream>
# include <vector>

# include "TApplication.h"
# include "TROOT.h"
# include "TFile.h"
# include "TTree.h"
# include "TGraph.h"
# include "TCanvas.h"
# include "TSpline.h"
# include "TH1F.h"

// Small class to open the file and getting the tree
//////////////////////////////////////////////////////////////////////////////////////
class TreeRead {
public:
    TreeRead(const char* fname, const char* treename) {
        file = TFile::Open(fname);
        if (file && !file->IsZombie()) {
            tree = (TTree*)file->Get(treename);
            if (!tree) {
                std::cerr << "Error: no tree found.\n";
                return;
            }
        }
    }
    ~TreeRead() {
        if (file) file->Close();
    }

    TTree* GetTree() const { return tree; }

private: 
    TFile* file = nullptr;
    TTree* tree = nullptr;
};
///////////////////////////////////////////////////////////////////////////////////

// Small struct to open branches
///////////////////////////////////////////////////////////////////////////////////
struct RawData {
    Int_t samps;
    Double_t raw_samps[5000];

    void SetupBranches(TTree* tree) {
        tree->SetBranchAddress("Ndata.moller.scint.samps", &samps);
        tree->SetBranchAddress("moller.scint.samps", raw_samps);
    }
};
////////////////////////////////////////////////////////////////////////////////////

// GetChannelData function
std::vector<Double_t> GetChannelData(TTree* tree, Int_t Evts, Int_t Chan,
                                     RawData& rawdata, const Int_t nSampsPerChan = 120) {
    std::cout << "Hi.... Getting data of: " << Evts << " event(s)\n" << std::endl;

    std::vector<Double_t> RawData; 

    // Evts loop
    for (Int_t i = 0; i < Evts; i++) {
        tree->GetEntry(i);
        const Int_t startChan = Chan * nSampsPerChan;

        // Channel loop
        for (Int_t j = startChan; j < startChan + nSampsPerChan; j++) {
            if (j < rawdata.samps) RawData.push_back(rawdata.raw_samps[j]);
        }
    }

    return RawData;
}

// PlotWaveForms function
void PlotWaveForms(TTree* tree, Int_t Evts, Int_t Chan,
                  RawData& rawdata, const Int_t nSampsPerChan = 120) {
    std::cout << "Plotting now....\n" << std::endl;

    for (int i = 0; i < Evts; i++) {
        tree->GetEntry(i); // Get the ith entrie
        TGraph *graph1 = new TGraph();
        const Int_t startSamp = Chan * nSampsPerChan;

        for (int j = startSamp; j < startSamp + nSampsPerChan; j++) {
            if (j < rawdata.samps) { 
                graph1->SetPoint(graph1->GetN(), j, rawdata.raw_samps[j]); // x, y points of the graph (index and amplitude)
            }
        }

        TCanvas *c = new TCanvas(Form("c%d", i), Form("Event%i", i), 800, 600);
        
        graph1->SetMarkerStyle(20); // Circle data points
        graph1->SetMarkerColor(kRed);
        graph1->SetMarkerSize(0.8);

        graph1->SetTitle(Form("Waveform for Event %d in channel %d;Sample Index;ADC Counts", i, Chan));
        graph1->Draw("AP");

        // Splines
        TSpline3 *spline1 = new TSpline3("spline1", graph1);

        spline1->SetLineColor(kRed);
        spline1->Draw("SAME");

        //c->SaveAs(Form("waveform_event%d_dotted.png", i));
    }
}

// PrintRawData function
void PrintRawData(TTree* tree, Int_t Evts, Int_t Chan, RawData& rawdata, const Int_t nSampsPerChan = 120) {
    std::cout << "Ok...! Printing data now....\n" << std::endl;

    const Int_t startSamp = Chan * nSampsPerChan;
    for (int i = 0; i < Evts; i++) {
        tree->GetEntry(i);
        std::cout << "==============================================\n"
                  << "=============== Event " << i << " =====================" << std::endl;

        for (int j = startSamp; j < startSamp + nSampsPerChan; j++) {
            std::cout << "Sample " << j << " value: " << rawdata.raw_samps[j] << std::endl;
        }
    }
}

// Generate the pulse height spectrum of pulse peak
void PulsePeakSpect(TTree* tree, Int_t Chan, RawData& rawdata, const Int_t nSampsPerChan = 120) {
    std::cout << "Here is the pulse peak spectum for channel " << Chan << std::endl;

    const Int_t nentries = tree->GetEntries();
    std::vector<Double_t> AllMaxVals;
    AllMaxVals.reserve(nentries);
    Double_t MaxVal;

    const Int_t startSamp = Chan * nSampsPerChan;
    const Int_t endSamp = startSamp + nSampsPerChan;
    
    for (Int_t i = 0; i < nentries; i++) {
        tree->GetEntry(i);
        MaxVal = *std::max_element(rawdata.raw_samps + startSamp, rawdata.raw_samps + endSamp);
        AllMaxVals.push_back(MaxVal);
    }

    TCanvas* c_hist = new TCanvas("c_hists", "canvas2", 800, 600);

    // Histogram parameters
    Int_t nbins = 100;
    Int_t MinX = *std::min_element(AllMaxVals.begin(), AllMaxVals.end());
    Int_t MaxX = *std::max_element(AllMaxVals.begin(), AllMaxVals.end());

    
    TH1F* hist = new TH1F("Max Val", Form("Pulse height spectrum of channel %d", Chan), nbins, MinX, MaxX);

    for (auto val : AllMaxVals) {
        hist->Fill(val);
    }

    hist->Draw();
    //gApplication->Run();

    //c_hist->SaveAs("hist.png");
}

// This is the main function of the script
void FadcScintDataProcess(const char* fname, const char* treename, Int_t Evts, Int_t Chan) {
    gROOT->Clear();
    gROOT->DeleteAll();
    
    // open the file and the tree from above TreeRead class
    TreeRead gettree(fname, treename);
    TTree* tree = gettree.GetTree();

    // Setup branches from the struct
    RawData rawdata;
    rawdata.SetupBranches(tree);

    // Get raw data vector
    std::vector<Double_t> RawDataVec = GetChannelData(tree, Evts, Chan, rawdata);
    std::cout << "Size of the RawData vector: " << RawDataVec.size() << std::endl;

    // Plot events
    //PlotWaveForms(tree, Evts, Chan, rawdata);

    // Print rawdata if you want
    PrintRawData(tree, Evts, Chan, rawdata);

    // Pulse height spectrum
    //PulsePeakSpect(tree, Chan, rawdata);

    std::cout << "The end!!!" << std::endl;
}
