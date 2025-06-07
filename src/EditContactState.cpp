#include <iostream>
#include <cstdlib>

#include "EditContactState.h"
#include "MainMenuState.h"
#include "InputHandler.h"


void EditContactState::enter() {
#ifdef _WIN32 // For Windows
    system("cls");
#else // For Linux and macOS
    system("clear");
#endif
    std::cout << "\n--- Edit Contact ---\n";
}

void EditContactState::display() const {
    
}

std::unique_ptr<State> EditContactState::handleInput(Phonebook& phonebook) {
    if (phonebook.isEmpty()) {
        std::cout << "Phonebook is empty. Nothing to edit.\n";
        return std::make_unique<MainMenuState>();
    }

    int idToEdit = InputHandler::getIntInput("Enter contact id: ");

    std::string newName = InputHandler::getStringInput("Enter new Name (leave blank to keep current): ");
    std::string newPhone = InputHandler::getStringInput("Enter new Phone (leave blank to keep current): ");


    Contact_Model edited_contact = Contact_Model(newName, newPhone);


    // fungsionalitas untuk edit
    phonebook.editContact(idToEdit, edited_contact);


    std::cout << "Contact " << newName << " has been edited\n";

    return std::make_unique<MainMenuState>();
}