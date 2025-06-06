#include "StateMachine.h"
#include "MainMenuState.h"
#include <iostream>

StateMachine::StateMachine() {
    running = true;
    transitionTo(std::make_unique<MainMenuState>()); // mulai dengan main menu
}

void StateMachine::run() {
    while(running) {
        if(currentState) {
            currentState->enter();
            currentState->display();
            std::unique_ptr<State> nextState = currentState->handleInput(phonebook);

            if(nextState) {
                transitionTo(std::move(nextState));
            } else {
                running = false;
            }
        }
    }
    std::cout << "Exiting Phonebook application. Goodbye!\n";
}

void StateMachine::transitionTo(std::unique_ptr<State> newState) {
    currentState = std::move(newState);
}
