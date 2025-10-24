//////////////////////////////////////////////////////////////////////
// Script to execute analyzer command
//
//////////////////////////////////////////////////////////////////////

# include "AnalysisManager.h"

void Script() {
    //gSystem->Load("build/lib/libFileHandler.so");

    AnalysisManager analyzer;

    analyzer.Start();
    //analyzer.PromtAndPlot();
}
