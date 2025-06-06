#ifndef EDITCONTACT_STATE_H
#define EDITCONTACT_STATE_H

#include "State.h"

class EditContactState : public State
{
    void enter() override;
    std::unique_ptr<State> handleInput(Phonebook &phonebook) override;
    void display() const override;
};

#endif // EDITCONTACT_STATE_H
