#include <iostream>
#include <cstdlib>

#include "DeleteContactState.h"
#include "MainMenuState.h"
#include "InputHandler.h"


void DeleteContactState::enter() {
#ifdef _WIN32 // For Windows
    system("cls");
#else // For Linux and macOS
    system("clear");
#endif
    std::cout << "\n--- Delete Contact ---\n";
}

void DeleteContactState::display() const {
    
}

std::unique_ptr<State> DeleteContactState::handleInput(Phonebook& phonebook) {
    if (phonebook.isEmpty()) {
        std::cout << "Phonebook is empty. Nothing to delete.\n";
        return std::make_unique<MainMenuState>();
    }

    int idToDelete = InputHandler::getIntInput("Enter contact id to delete: ");
    
    // fungsionalitas delete
    phonebook.deleteContact(idToDelete);


    return std::make_unique<MainMenuState>();
}