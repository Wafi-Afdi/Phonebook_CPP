#include <iostream>
#include <cstdlib>

#include "MainMenuState.h"
#include "AddContactState.h"
#include "ViewContactState.h"
#include "EditContactState.h"
#include "DeleteContactState.h"
#include "SearchContactState.h"
#include "InputHandler.h"

void MainMenuState::enter()
{

    std::cout << "\n--- Main Menu Phonebook CLI App ---\n";
}

void MainMenuState::display() const
{
    std::cout << "1. Add Contact\n";
    std::cout << "2. View Contacts\n";
    std::cout << "3. Edit Contact\n";
    std::cout << "4. Delete Contact\n";
    std::cout << "5. Search Contact\n";
    std::cout << "6. Print to text\n";
    std::cout << "7. Exit\n";
}

std::unique_ptr<State> MainMenuState::handleInput(Phonebook &phonebook)
{
    int choice = InputHandler::getIntInput("Enter your choice (type the number): ");

    switch (choice) {
        case 1: return std::make_unique<AddContactState>();
        case 2: return std::make_unique<ViewContactState>();
        case 3: return std::make_unique<EditContactState>();
        case 4: return std::make_unique<DeleteContactState>();
        case 5: return std::make_unique<SearchContactState>();
        case 6: 
        phonebook.saveContactsFile();
            std::cout << "File saved to " << CONTACT_PATH << "\n";
            return std::make_unique<MainMenuState>();
        case 7: return nullptr; // Signal to exit
        default:
            std::cout << "Invalid choice. Please try again.\n";
            return std::make_unique<MainMenuState>(); // Stay in Main Menu
    }
}