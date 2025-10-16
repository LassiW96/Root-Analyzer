//////////////////////////////////////////////////////////////////////
// Script to execute analyzer command
//
//////////////////////////////////////////////////////////////////////

# include "RootAnalyzer.h"

void Script() {
    //gSystem->Load("build/lib/libRootAnalyzer.so");

    RootAnalyzer analyzer;

    analyzer.OpenFile();
    analyzer.AccessTree();
    analyzer.SetupBranches();
    analyzer.PromtAndPlot();
}
