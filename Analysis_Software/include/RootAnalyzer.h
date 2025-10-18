//////////////////////////////////////////////////////////////////////
// RootAnalyzer header file
//
// Functions:   - Opening a root file
//              - Setting up branches
//              - Print branch data
//              - Plot waveforms
//              - Plot histograms
//////////////////////////////////////////////////////////////////////

# ifndef ROOTANALYZER_H
# define ROOTANALYZER_H

# include <iostream>
# include <fstream>
# include <vector>
# include <map>
# include <string>
# include <any>

# include "TROOT.h"
# include "TTree.h"

struct BranchData {
    std::string name;               // Branch name
    std::string count;              // Branch data count
    std::string type;               // Branch data type
    Int_t ndata = 0;                // Element count per event

    std::vector<Double_t> bufferD;  // Vector for double data
    std::vector<Float_t> bufferF;   // Vector for float data
};

class RootAnalyzer {
public:
    RootAnalyzer();
    ~RootAnalyzer();

    bool OpenFile();

    // Helper function to print file info
    void PrintFilecontent() const;

    bool AccessTree();

    bool SetupBranches();

    // Waveform plotting functions
    void PromtAndPlot();

    void PromptUser();

private:
    TFile* file = nullptr;
    TTree* tree = nullptr;
    std::vector<std::string> connectedBranches;
    std::map<std::string, BranchData> branchData;

    // Cannot call this outside the class, call PromptAndPlot instead
    void PlotSamples(const std::string& branch, int nEvents);
};

# endif
