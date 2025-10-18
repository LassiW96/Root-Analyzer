////////////////////////////////////////////////////////////////////////
// Source file
// 
////////////////////////////////////////////////////////////////////////

// Stream interface for manipulating strings. This will be needed in
// branch opening
# include <sstream>

# include "RootAnalyzer.h"

# include "TFile.h"
# include "TKey.h"
# include "TObject.h"
# include "TBranch.h"
# include "TLeaf.h"
# include "TGraph.h"
# include "TCanvas.h"
# include "TSpline.h"

RootAnalyzer::RootAnalyzer() : file(nullptr), tree(nullptr) {}

RootAnalyzer::~RootAnalyzer() {
    if (file) {
        file->Close();
        delete file;
    }
}

// File opening
/////////////////////////////////////////////////////////////////////////
bool RootAnalyzer::OpenFile()
{
    while (true) {
        std::string fname = "pion_det_fadc_replayed_177_seg0_1.root";
        // std::cout << "Enter the file name: ";
        // std::cin >> fname;

        file = TFile::Open(fname.c_str(), "READ");    

        if (file || !file->IsZombie()) {
            std::cout << "\nFile " << fname << " opened successfully!" << std::endl;
            PrintFilecontent();
            break;
        }

        else {
            std::cerr << "Error: Couldn't open the file " << fname 
                      << "\nCheck the file name" << std::endl;
        }
    }

    return true;
}

// Print file info
/////////////////////////////////////////////////////////////////////////
void RootAnalyzer::PrintFilecontent() const
{
    if (!file) {
        std::cerr << "Error: There's no file" << std::endl;
    }

    std::cout << "\n===== File Content Summary =====" << std::endl;

    TIter nextkey(file->GetListOfKeys());
    TKey* key;
    while ((key = (TKey*)nextkey())) {
        TObject* obj = key->ReadObj();
        std::string classname = obj->ClassName();
        std::cout << "Object " << key->GetName() << " (" << classname
                  << ")" << std::endl;

        // If the object inherits from TTree class, print branches
        if (obj->InheritsFrom(TTree::Class())) {
            TTree* t = (TTree*)obj;
            TObjArray* branches = t->GetListOfBranches();
            std::cout << "Branches: " << std::endl;
            for (int i = 0; i < branches->GetEntries(); i++) {
                std::cout << "      - " << branches->At(i)->GetName() << std::endl;
            }
        }
    }

    std::cout << "==================================\n" << std::endl;
}

// Tree opening
/////////////////////////////////////////////////////////////////////////
bool RootAnalyzer::AccessTree()
{
    if (!file) {
        std::cerr << "Error: There's no file open, call OpenFile() first!"
                  << std::endl;
        return false;
    }

    while (true) {
        std::string treename = "T";
        // std::cout << "What's the name of the tree you want to access: ";
        // std::cin >> treename;

        tree = dynamic_cast<TTree*>(file->Get(treename.c_str()));

        if (!tree) {
            std::cerr << "Error: No such tree in the file " << file->GetName() 
                    << "\nCheck the tree name again" << std::endl;
        }

        else {
        std::cout << "Tree " << treename << " opened successfully!" 
                  << "\n=========================================" << std::endl;
            break;
        }
    }
    return true;
}

// Setup branches
/////////////////////////////////////////////////////////////////////////////
bool RootAnalyzer::SetupBranches() 
{
    if (!tree) {
        std::cerr << "Error: No tree specified, call AccessTree() first!"
                  << std::endl;
        return false;
    }

    std::string input = "moller.scint.samps";
    // std::cout << "Enter branch names to load separated by commas: ";
    // std::getline(std::cin >> std::ws, input);

    // Stringstream object to manipulate string input
    std::stringstream ss(input);
    std::string branchName;

    // Read a line from ss
    while(std::getline(ss, branchName, ',')) {
        // Erase white spaces
        branchName.erase(0, branchName.find_first_not_of(" \t"));
        branchName.erase(branchName.find_last_not_of(" \t") + 1);
        if (branchName.empty()) continue;

        std::string branchCount = "Ndata." + branchName;

        // Get that branch from the tree
        TBranch* brData = tree->GetBranch(branchName.c_str());
        TBranch* brCount = tree->GetBranch(branchCount.c_str());

        if (!brData || !brCount) {
            std::cerr << "Warning: Couldn't find Ndata for "
                      << branchName << std::endl;
            continue;
            
        }

        // Get branch data type from the leaf
        TLeaf* leaf = brData->GetLeaf(branchName.c_str());
        if (!leaf) {
            std::cerr << "Error: No leaf found" << std::endl;
            continue;
        }

        std::string leafType = leaf->GetTypeName();

        // Setup arrays for that branch
        BranchData arr;
        arr.name = branchName;
        arr.count = branchCount;

        // Get the count branch first to determine the data type first
        tree->SetBranchAddress(arr.count.c_str(), &arr.ndata);

        if (leafType == "Double_t") {
            arr.type = "double";
            arr.bufferD.resize(5000);
            tree->SetBranchAddress(arr.name.c_str(), arr.bufferD.data());
            std::cout << "\nBuffer name: " << arr.name << std::endl;
        }

        else if (leafType == "Float_t") {
            arr.type = "float";
            arr.bufferF.resize(5000);
            tree->SetBranchAddress(arr.name.c_str(), arr.bufferF.data());
            std::cout << "\nBuffer name: " << arr.name.c_str() << std::endl;
        }

        else {
            std::cerr << "Error: Unsupported data type" << std::endl;
            continue;
        }

        for (int ii = 0; ii < tree->GetEntries(); ii++) {
            // Call Getentry() before filling up the vector. Important!
            tree->GetEntry(ii);
            branchData[arr.name] = arr;
        }

        connectedBranches.push_back(branchName);

        std::cout << "Printing branchData map\n";
        for (auto it = branchData.begin(); it != branchData.end(); ++it) {
            std::cout << "Branch: " << it->first << std::endl;
            std::cout << "  Type: " << it->second.type << std::endl;
            std::cout << "  Ndata: " << it->second.ndata << std::endl;

            if (!it->second.bufferD.empty()) {
                std::cout << "  First few doubles: ";
                for (size_t i = 0; i < std::min<size_t>(5, it->second.bufferD.size()); ++i)
                    std::cout << it->second.bufferD[i] << " ";
                std::cout << std::endl;
            }
        
            if (!it->second.bufferF.empty()) {
                std::cout << "  First few floats: ";
                for (size_t i = 0; i < std::min<size_t>(5, it->second.bufferF.size()); ++i)
                    std::cout << it->second.bufferF[i] << " ";
                std::cout << std::endl;
            }
        }


        std::cout << "Connected: " << branchName
                  << " (" << arr.type << ", Ndata = " << arr.count << ")\n";
    }

    std::cout << "===============================================\n" 
              << std::endl;
    return true;
}

// Plotting functions
//____________________________________________________________________________
// Samples plotting (Eg: Waveforms)
//////////////////////////////////////////////////////////////////////////////
void RootAnalyzer::PlotSamples(const std::string& branch, int nEvents)
{
    auto it = branchData.find(branch);
    const BranchData& arr = it->second;
    std::cout << "\nBuffer name: " << arr.name 
              << " type: " << arr.type << std::endl;

    for (int i = 0; i < nEvents; i++) {
        if (arr.bufferD.empty() && arr.bufferF.empty()) {
            std::cerr << "Error: Empty buffer!\n";
            return;
        }

        TGraph *graph1 = new TGraph();
        for (int j = 0; j < arr.ndata; j++) {
            graph1->SetPoint(graph1->GetN(), j, arr.bufferD[j]);
        }    

        // Drawing
        TCanvas *c = new TCanvas(Form("c%d", i), Form("Event%i", i), 800, 600);
        
        graph1->SetMarkerStyle(20);
        graph1->SetMarkerColor(kRed);
        graph1->SetMarkerSize(0.8);

        graph1->SetTitle(Form("Waveform for Event %d;Sample Index;ADC Counts", i));
        graph1->Draw("AP");

        // Splines fit
        TSpline3 *spline1 = new TSpline3("spline1", graph1);

        spline1->SetLineColor(kRed);
        spline1->Draw("SAME");
    }
}

// Prompting the number of events from the user and plot
///////////////////////////////////////////////////////////////////////////////
void RootAnalyzer::PromtAndPlot()
{
    if (!tree) {
        std::cerr << "Error: No tree opened!" << std::endl;
        return;
    }

    std::cout << "Available branches:\n";
    for (int i = 0; i < connectedBranches.size(); i++) {
        std::cout << " [" << i << "] " << connectedBranches[i] << std::endl;
    }

    int branchIdx = 0;
    // std::cout << "Select the branch idx to plot: ";
    // std::cin >> branchIdx;

    if (branchIdx < 0 || branchIdx > (int)connectedBranches.size()) {
        std::cerr << "Error: Invalid branch index!" << std::endl;
        return;
    }

    std::string branch = connectedBranches[branchIdx];

    int nEvents = 2;
    // std::cout << "Enter the number of events to plot: ";
    // std::cin >> nEvents;
    std::cout << "\nPlotting " << branch << " for " << nEvents <<" events\n"
              << "=====================================================\n"; 
    PlotSamples(branch, nEvents);
}

// Prompt user for plots
////////////////////////////////////////////////////////////////////////////////////
void RootAnalyzer::PromptUser()
{
    
}
