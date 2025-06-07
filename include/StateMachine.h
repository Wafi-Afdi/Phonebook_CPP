#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <memory>
#include <fstream> 
#include <sstream>


#include "State.h"
#include "PhoneBook.h"


class StateMachine {
public:
    StateMachine();
    void run();
    void transitionTo(std::unique_ptr<State> newState);

    bool parseFromFile(std::string filename = CONTACT_PATH);

private:
    std::unique_ptr<State> currentState;
    Phonebook phonebook;
    bool running;
};

#endif