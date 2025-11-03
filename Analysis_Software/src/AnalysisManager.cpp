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

    while (true) {
        std::string filename = PromptFilename();    // Prompt for the filename
        if(filename.empty()) {
            std::cerr << "\nFilename is empty! Try again\n";
        }

        fileLoaded = analyzer->OpenFile(filename);
        // File content will be printed through OpenFile

        if (fileLoaded) {
            std::cout << "\nFile loaded successfully!\n";
            BranchSetup();
            std::cout << "\nBranch setup successfull!\n";
            break;
        }
    }

    std::cout << "\nDone. Good bye!!!\n";
}

void AnalysisManager::WelcomeHeader() const
{
    std::cout << "===========================================\n";
    std::cout << "======== Root file analyzer v1.0 ==========\n\n";
    std::cout << "================ Welcome! =================\n";
    std::cout << "===========================================\n";
}

std::string AnalysisManager::PromptFilename() const
{
    std::string filename;
    std::cout << "Enter the filename with the path: ";
    std::getline(std::cin, filename);

    if (filename.empty()) {
        std::cerr << "No filename entered. Aborting!\n";
        return "";
    }

    return filename;
}

// Tree and branch setup
//////////////////////////////////////////////////////////////////////////////
void AnalysisManager::BranchSetup()
{
    while (true) {
        std::string treename;
        std::cout << "\nEnter the tree name to load: ";
        std::cin >> treename;
    
        treeOpen = analyzer->AccessTree(treename);
    
        if (treeOpen) {
            while (true) {
                std::string input;
                std::cout << "Enter branch names to load separated by commas: ";
                std::getline(std::cin >> std::ws, input);
            
                // Stringstream object to manipulate string input
                std::stringstream ss(input);
                branchSetup = analyzer->SetupBranches(ss);

                if (branchSetup) {
                    std::cout << "\nBranch open successfull!\n";
                    break;
                }

                else {
                    std::cout << "\nCouldn't open that branch! Try again.\n";
                }
            }
            break;
        }
    
        else {
            std::cerr << "\nCould not open that tree!\n";
        }
    }
}

// Prompt the user for analysis type
//////////////////////////////////////////////////////////////////////////////
void AnalysisManager::PromptUser()
{
    std::cout << "==== Following options are available ======\n";
    std::cout << " 1. Waveforms.\n";
    std::cout << " 2. Pulse height spectrum.\n";
    std::cout << " 3. Timing destribution.\n";
    std::cout << " 4. Open a different tree.\n\n";
    std::cout << " 5. Exit.\n";
    std::cout << "===========================================\n";

    Int_t choice = 0;

    while (true) {
        std::cout << "\nEnter the choice from the above list: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, ',');
            std::cerr << "\nInvalid input. Please enter a number between 1 & 6!\n";
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
