#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <iostream>
#include <string>
#include <limits>

namespace InputHandler {
    std::string getStringInput(const std::string& prompt);
    int getIntInput(const std::string& prompt);
    void clearInputBuffer();
}

#endif // INPUT_HANDLER_H