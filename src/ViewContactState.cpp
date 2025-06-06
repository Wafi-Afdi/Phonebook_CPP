#include <iostream>
#include <cstdlib>

#include "ViewContactState.h"
#include "MainMenuState.h"
#include "InputHandler.h"

void ViewContactState::enter()
{
#ifdef _WIN32 // For Windows
    system("cls");
#else // For Linux and macOS
    system("clear");
#endif
    std::cout << "\n--- Contact List ---\n";
}

void ViewContactState::display() const
{
    // Display semua kontak
}

std::unique_ptr<State> ViewContactState::handleInput(Phonebook &phonebook)
{
    std::cout << "\nPress Enter to return to Main Menu...";
    InputHandler::getStringInput(""); 
    return std::make_unique<MainMenuState>();
}