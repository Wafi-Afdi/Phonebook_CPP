#ifndef VIEWCONTACT_STATE_H
#define VIEWCONTACT_STATE_H

#include "State.h"

class ViewContactState : public State
{
    void enter() override;
    std::unique_ptr<State> handleInput(Phonebook &phonebook) override;
    void display() const override;
};

#endif // VIEWCONTACT_STATE_H
