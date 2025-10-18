////////////////////////////////////////////////////////////////////////////
// Source file of the analysis manager
//
////////////////////////////////////////////////////////////////////////////

# include "AnalysisManager.h"

AnalysisManager::AnalysisManager() 
{
    analyzer = std::make_unique<RootAnalyzer>();
}

void AnalysisManager::Start()
{
    WelcomeHeader();                            // Call welcome header first
    std::string filename = PromptFilename();    // Prompt for the filename

    if (!filename.empty()) {
        if (analyzer->OpenFile()) {
            fileLoaded = true;
            std::cout << "\nFile loaded successfully.\n";
        }
    }

    else {
        std::cerr << "\nFailed to load the file " << filename << std::endl;
        return;
    }
}

void AnalysisManager::WelcomeHeader() const
{
    std::cout << "===========================================\n";
    std::cout << "=========== Root file analyzer ============\n\n";
    std::cout << "== Following functions are served: \n";
    std::cout << " 1. Printing a data summary.\n";
    std::cout << " 2. Waveforms.\n";
    std::cout << " 3. Pulse height spectrum.\n";
    std::cout << " 4. Timing destribution.\n";
    std::cout << "===========================================\n";
}

std::string AnalysisManager::PromptFilename() const
{
    std::string filename;
    std::cout << "Enter the filename: ";
    std::getline(std::cin, filename);

    if (filename.empty()) {
        std::cerr << "No filename entered. Aborting.\n";
        return "";
    }

    return filename;
}
