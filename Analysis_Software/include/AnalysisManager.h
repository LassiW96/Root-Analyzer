/////////////////////////////////////////////////////////////////////////
// Main manager class header of the Analyzer
//
// Just the layout and prompts
//
/////////////////////////////////////////////////////////////////////////

# ifndef ANALYSISMANAGER_H
# define ANALYSISMANAGER_H

# include <iostream>
# include <string>
# include <memory>

# include "RootAnalyzer.h"

class AnalysisManager{
public:
    AnalysisManager();
    ~AnalysisManager();

    void Start();               // Starting point of the analyzer
    //void Exit();

private:
    // Workflow functions
    void WelcomeHeader() const;
    std::string PromptFilename() const;

    // Data memebers
    //bool running = true;
    std::unique_ptr<RootAnalyzer> analyzer;
    bool fileLoaded = false;
};

# endif
