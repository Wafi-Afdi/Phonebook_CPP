
#include <iostream>
#include <cstdlib> 

#include "SearchContactState.h"
#include "MainMenuState.h"
#include "InputHandler.h"

void SearchContactState::enter() {
    std::cout << "\n--- Search Contacts ---\n";
}

void SearchContactState::display() const {
    
}

std::unique_ptr<State> SearchContactState::handleInput(Phonebook& phonebook) {
    // if (phonebook.isEmpty()) {
    //     std::cout << "Phonebook is empty. Nothing to search.\n";
    //     return std::make_unique<MainMenuState>();
    // }

    std::string query = InputHandler::getStringInput("Enter search query (name or phone): ");

    // fungsionalitas search dan display

    
    std::cout << "\nPress Enter to return to Main Menu...";
    InputHandler::getStringInput(""); // Wait for user to press enter
    return std::make_unique<MainMenuState>();
}