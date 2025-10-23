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
# include <sstream>

# include "FileHandler.h"
# include "GeneratePlots.h"

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
    void BranchSetup();
    void PromptUser();          // Prompt user for analysis type

    // Data memebers
    //bool running = true;
    std::unique_ptr<FileHandler> analyzer;
    bool fileLoaded = false;
    bool treeOpen = false;
    bool branchSetup = false;
};

# endif
