//////////////////////////////////////////////////////////////////////
// Script to execute analyzer command
//
//////////////////////////////////////////////////////////////////////

# include "FileHandler.h"

void Script() {
    //gSystem->Load("build/lib/libFileHandler.so");

    FileHandler analyzer;

    analyzer.OpenFile();
    analyzer.AccessTree();
    analyzer.SetupBranches();
    //analyzer.PromtAndPlot();
}
