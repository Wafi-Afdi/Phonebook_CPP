#ifndef DELETECONTACT_STATE_H
#define DELETECONTACT_STATE_H

#include "State.h"

class DeleteContactState : public State
{
    void enter() override;
    std::unique_ptr<State> handleInput(Phonebook &phonebook) override;
    void display() const override;
};

#endif // DELETECONTACT_STATE_H
