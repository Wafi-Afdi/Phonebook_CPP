#include <iostream>
#include "StateMachine.h"

int main() {
    StateMachine app;
    if(app.parseFromFile() == false) {
        std::cout << "Failed to parse file";
    }
    app.run();
    return 0;
}