////////////////////////////////////////////////////////////////////////
// Source file
// 
////////////////////////////////////////////////////////////////////////

// Stream interface for manipulating strings. This will be needed in
// branch opening
# include <sstream>

# include "FileHandler.h"

# include "TFile.h"
# include "TKey.h"
# include "TObject.h"
# include "TBranch.h"
# include "TLeaf.h"
# include "TGraph.h"
# include "TCanvas.h"
# include "TSpline.h"

FileHandler::FileHandler() : file(nullptr), tree(nullptr) {}

FileHandler::~FileHandler() {
    if (file) {
        file->Close();
        delete file;
    }
}

// File opening
/////////////////////////////////////////////////////////////////////////
bool FileHandler::OpenFile(std::string& filename)
{
        file = TFile::Open(filename.c_str(), "READ");    

        if (file && !file->IsZombie()) {
            std::cout << "\nFile " << filename << " opened successfully!" 
                      << std::endl;
            PrintFilecontent();
            return true;
        }

        else {
            std::cerr << "Error: Couldn't open the file " << filename 
                      << "\nCheck the file name" << std::endl;
            
            // Clear any existing file before opening again
            return false;
        }
}

// Print file info
/////////////////////////////////////////////////////////////////////////
void FileHandler::PrintFilecontent() const
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
bool FileHandler::AccessTree(std::string& treename)
{
    if (!file) {
        std::cerr << "Error: There's no file open, call OpenFile() first!"
                  << std::endl;
        return false;
    }

    else {
        tree = dynamic_cast<TTree*>(file->Get(treename.c_str()));

        if (!tree) {
            std::cerr << "Error: No such tree in the file " << file->GetName() 
                        << "\nCheck the tree name again" << std::endl;
            return false;
        }
        else {
            std::cout << "Tree " << treename << " opened successfully!" 
                        << "\n=========================================\n";
            return true;
        }
    }
}

// Setup branches
/////////////////////////////////////////////////////////////////////////////
bool FileHandler::SetupBranches(std::stringstream& ss) 
{
    if (!tree) {
        std::cerr << "Error: No tree specified, call AccessTree() first!"
                  << std::endl;
        return false;
    }

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

        if (!brData) {
            std::cerr << "Warning: Couldn't find data for "
                      << branchName << std::endl;
            continue;
            
        }

        if (!brCount) {
            std::cerr << "Warning: Couldn't find an Ndata branch for "
                      << branchName << "; Opening as a normal branch.\n";
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
        if (brCount) arr.count = branchCount;

        // Get the count branch first to determine the data type first
        if (brCount) tree->SetBranchAddress(arr.count.c_str(), &arr.ndata);

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

        else if (leafType == "Int_t") {
            arr.type = "int";
            arr.bufferI.resize(5000);
            tree->SetBranchAddress(arr.name.c_str(), arr.bufferI.data());
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
            if (brCount) std::cout << "  Ndata: " << it->second.ndata << std::endl;

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

            if (!it->second.bufferI.empty()) {
                std::cout << "  First few integers: ";
                for (size_t i = 0; i < std::min<size_t>(5, it->second.bufferI.size()); ++i)
                    std::cout << it->second.bufferI[i] << " ";
                std::cout << std::endl;
            }
        }

        std::cout << "Connected: " << branchName
                  << " (" << arr.type << ")\n";
        if (brCount) std::cout << "Ndata " << arr.ndata << std::endl;
    }

    std::cout << "===============================================\n" 
              << std::endl;
    return true;
}

