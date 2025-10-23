/////////////////////////////////////////////////////////////////////////////
// Plotting class header
//
/////////////////////////////////////////////////////////////////////////////

# ifndef GENERATEPLOTS_H
# define GENERATEPLOTS_H

# include <iostream>
# include <vector>
# include <string>
# include <map>

# include "FileHandler.h"

class GeneratePlots {
public:
    void PlotWaveForms(const std::string& branch, int nEvents);

private:
    std::map<std::string, BranchData> branchData;
};

# endif
