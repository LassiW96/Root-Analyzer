//////////////////////////////////////////////////////////////////////
// Mian script 
//
//////////////////////////////////////////////////////////////////////

# include "FileHandler.h"

int main() {
    FileHandler analyzer;

    analyzer.OpenFile();

    if (analyzer.OpenFile() == false) {
        return 0;
    }
    
    analyzer.AccessTree();
    analyzer.SetupBranches();

    return 0;
}
