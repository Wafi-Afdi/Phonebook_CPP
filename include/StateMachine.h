#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include "PhoneBook.h"
#include <memory>

class StateMachine {
public:
    StateMachine();
    void run();
    void transitionTo(std::unique_ptr<State> newState);

private:
    std::unique_ptr<State> currentState;
    Phonebook phonebook;
    bool running;
};

#endif