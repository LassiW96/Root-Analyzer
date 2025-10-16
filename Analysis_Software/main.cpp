//////////////////////////////////////////////////////////////////////
// Mian script 
//
//////////////////////////////////////////////////////////////////////

# include "RootAnalyzer.h"

int main() {
    RootAnalyzer analyzer;

    analyzer.OpenFile();

    if (analyzer.OpenFile() == false) {
        return 0;
    }
    
    analyzer.AccessTree();
    analyzer.SetupBranches();

    return 0;
}
