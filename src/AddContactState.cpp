#include "AddContactState.h"
#include "MainMenuState.h"
#include "InputHandler.h"
#include <iostream>
#include <cstdlib>

void AddContactState::enter()
{
#ifdef _WIN32 // For Windows
    system("cls");
#else // For Linux and macOS
    system("clear");
#endif
    std::cout << "\n--- Add New Contact ---\n";
}

void AddContactState::display() const
{
    
}

std::unique_ptr<State> AddContactState::handleInput(Phonebook &phonebook)
{
    std::string name = InputHandler::getStringInput("Enter Name: ");
    std::string phone = InputHandler::getStringInput("Enter Phone: ");

    Contact_Model newContact = Contact_Model(name, phone);

    phonebook.addContact(newContact);

    std::cout << "New contact added\n";
    InputHandler::getStringInput("Press Enter to return to Main Menu...\n");
    
    return std::make_unique<MainMenuState>(); 
}