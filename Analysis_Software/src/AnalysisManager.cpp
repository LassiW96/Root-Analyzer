////////////////////////////////////////////////////////////////////////////
// Source file of the analysis manager
//
////////////////////////////////////////////////////////////////////////////

# include "AnalysisManager.h"

AnalysisManager::AnalysisManager() 
{
    analyzer = std::make_unique<FileHandler>();
}

void AnalysisManager::Start()
{
    WelcomeHeader();                            // Call welcome header first
    std::string filename = PromptFilename();    // Prompt for the filename

    if (!filename.empty()) {
        fileLoaded = analyzer->OpenFile(filename);
        // File content will be printed through OpenFile
        std::cout << "\nFile loaded successfully!\n";
    }

    else {
        std::cerr << "\nFilename is empy!\n";
        return;
    }

    if (fileLoaded = true) {

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

// Tree and branch setup
//////////////////////////////////////////////////////////////////////////////
void AnalysisManager::BranchSetup()
{
    std::string treename;
    std::cout << "\nEnter the tree name to load:";
    std::cin >> treename;

    treeOpen = analyzer->AccessTree(treename);

    if (treeOpen == true) {
        std::string input;
        std::cout << "Enter branch names to load separated by commas: ";
        std::getline(std::cin >> std::ws, input);
    
        // Stringstream object to manipulate string input
        std::stringstream ss(input);
        std::string branchName;
    }
}


// Prompt the user for analysis type
//////////////////////////////////////////////////////////////////////////////
void AnalysisManager::PromptUser()
{
    Int_t choice = 0;

    while (true) {
        std::cout << "\nEnter the choice of analysis from the above list."
                  << "Type 5 to exit.";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, ',');
            std::cerr << "\nInvalid input. Please enter a number between 1 & 5!\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            break;
        
        default:
            break;
        }
    }
}
