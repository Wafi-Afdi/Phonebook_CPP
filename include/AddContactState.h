#ifndef ADDCONTACT_STATE_H
#define ADDCONTACT_STATE_H

#include "State.h"

class AddContactState : public State
{
    void enter() override;
    std::unique_ptr<State> handleInput(Phonebook &phonebook) override;
    void display() const override;
};

#endif // ADDCONTACT_STATE_H
