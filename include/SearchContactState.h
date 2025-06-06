#ifndef SEARCHCONTACT_STATE_H
#define SEARCHCONTACT_STATE_H

#include "State.h"

class SearchContactState : public State
{
    void enter() override;
    std::unique_ptr<State> handleInput(Phonebook &phonebook) override;
    void display() const override;
};

#endif // SEARCHCONTACT_STATE_H
