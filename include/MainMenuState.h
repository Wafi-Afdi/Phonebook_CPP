#ifndef MAINMENU_STATE_H
#define MAINMENU_STATE_H

#include "State.h"

class MainMenuState : public State
{
    void enter() override;
    std::unique_ptr<State> handleInput(Phonebook &phonebook) override;
    void display() const override;
};

#endif // MAINMENU_STATE_H
