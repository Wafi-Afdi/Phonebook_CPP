
#include <iostream>
#include <cstdlib> 

#include "SearchContactState.h"
#include "MainMenuState.h"
#include "InputHandler.h"

void SearchContactState::enter() {
#ifdef _WIN32 // For Windows
    system("cls");
#else // For Linux and macOS
    system("clear");
#endif
    std::cout << "\n--- Search Contacts ---\n";
}

void SearchContactState::display() const {
    
}

std::unique_ptr<State> SearchContactState::handleInput(Phonebook& phonebook) {
    if (phonebook.isEmpty()) {
        std::cout << "Phonebook is empty. Nothing to search.\n";
        return std::make_unique<MainMenuState>();
    }

    std::string query = InputHandler::getStringInput("Enter search query (name or phone): ");

    // fungsionalitas search dan display
    std::vector<Contact_Model> found_contacts = phonebook.searchContacts(query);

    if(found_contacts.size() == 0) {
        std::cout << "Zero results from search\n";
    }

    for (size_t i = 0; i < found_contacts.size(); i++) {
        cout << "\nContact " << (i + 1) << ":\n";
        cout << "ID: " << found_contacts[i].getId() << "\n";
        cout << "Name: " << found_contacts[i].getName() << "\n";
        cout << "Phone: " << found_contacts[i].getPhone() << "\n";
        cout << "-------------------------\n";
    }

    
    std::cout << "\nPress Enter to return to Main Menu...";
    InputHandler::getStringInput(""); // Wait for user to press enter
    return std::make_unique<MainMenuState>();
}