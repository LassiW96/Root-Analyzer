////////////////////////////////////////////////////////////////////////////
// Macro for getting the Timing distribution of a fadc_replayed data
// Just selecting raw data branch for now
// Pass the file name and the desired channel number for now
//
// Timing criteria: Get the first sample idx which goes 75% of the pulse
//                  peak
////////////////////////////////////////////////////////////////////////////

# include <iostream>
# include <vector>
# include <numeric>

# include "TROOT.h"
# include "TFile.h"
# include "TTree.h"
# include "TCanvas.h"
# include "TH1F.h"

using namespace std;

void TimingRes(const char* fname, Int_t Chan) {
    // Open the user specified file, print an error if the file is empty
    TFile* file = TFile::Open(fname);
    if (!file || file->IsZombie()) {
        cerr << "Errot: file couldn't open" << endl;
        return;
    }

    // Get the tree from the file, assuming the name of the tree is T
    TTree* tree = (TTree*)file->Get("T");
    if (!tree) {
        cerr << "Error: tree " << tree <<  " is not found,"
                " check the tree name" << endl;
        return;
    }

    Int_t nentries = tree->GetEntries();
    Int_t kNumSamples = 120;
    Double_t raw_samps[5000];
    vector<Double_t> AllMaxVals;
    AllMaxVals.reserve(nentries);
    Double_t MaxVal = 0.0;

    Double_t MeanPeakVal = 0.0;
    Double_t TVal = 0.0;
    vector<Double_t> AllTVals;

    tree->SetBranchAddress("moller.scint.samps", raw_samps);

    // Loop over each entry and get the maximum value
    for (Int_t i = 0; i < nentries; i++) {
        tree->GetEntry(i);
        const Int_t startChan = Chan * kNumSamples;
        const Int_t endChan = startChan + kNumSamples;

        MaxVal = *max_element(raw_samps + startChan, raw_samps + endChan);
        AllMaxVals.push_back(MaxVal);
    }

    MeanPeakVal = accumulate(AllMaxVals.begin(), AllMaxVals.end(), 0.0) / AllMaxVals.size();

    for (Int_t i = 0; i < nentries; i++) {
        tree->GetEntry(i);
        const Int_t startChan = Chan * kNumSamples;
        const Int_t endChan = startChan + kNumSamples;

        for (Int_t j = startChan; j < endChan; j++) {
            if (raw_samps[j] > 0.75 * MeanPeakVal) {
                TVal = j - startChan;
                break;
            }
        }

        AllTVals.push_back(TVal);

        if (i < 5) {
            cout << "TVal for Evt" << i << " = " << AllTVals[i] << endl;
        }

    }

    file->Close();

    // Move to the global directory. Important!!
    gROOT->cd();    

    // Draw a histogram
    // Get the canvas
    TCanvas* c = new TCanvas(Form("Chan%d_canvas", Chan), "canvas1", 800, 600);

    // Change the following histogram paramters accordingly
    Int_t nbins = 100;
    Double_t margin = 5.0;
    Int_t MinX = *min_element(AllTVals.begin(), AllTVals.end())-margin;
    Int_t MaxX = *max_element(AllTVals.begin(), AllTVals.end())+margin; 
    TH1F* hist = new TH1F(Form("Chan%d_hist", Chan), Form("Timing variation of channel %d", Chan), nbins, MinX, MaxX);

    // Fill the histogram
    for (auto val : AllTVals) {
        hist->Fill(val);
    }

    //gPad->SetLogy();
    hist->Draw();
    c->Update();

    c->SaveAs(Form("Pulse_peak_spectrum_of_channel_%d.png", Chan));
}
