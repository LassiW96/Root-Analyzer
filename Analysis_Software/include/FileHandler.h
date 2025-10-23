//////////////////////////////////////////////////////////////////////
// FileHandler header file
//
// Functions:   - Opening a root file
//              - Setting up branches
//              - Print branch data
//              - Plot waveforms
//              - Plot histograms
//////////////////////////////////////////////////////////////////////

# ifndef FILEHANDLER_H
# define FILEHANDLER_H

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

class FileHandler {
public:
    FileHandler();
    ~FileHandler();

    bool OpenFile(std::string& filename);
    bool AccessTree(std::string& treename);
    bool SetupBranches(std::stringstream& ss, std::string& branchName);

    // Helper function to print file info
    void PrintFilecontent() const;

private:
    TFile* file = nullptr;
    TTree* tree = nullptr;
    std::vector<std::string> connectedBranches;
    std::map<std::string, BranchData> branchData;

};

# endif
