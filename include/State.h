#ifndef STATE_H
#define STATE_H

#include <memory>
#include "PhoneBook.h"

// forward declaration
class StateMachine;

class State {
    public:
        virtual ~State() = default;

        virtual void enter() = 0;
        virtual std::unique_ptr<State> handleInput(Phonebook& phonebook) = 0;
        virtual void display() const = 0;
};

#endif // STATE_H