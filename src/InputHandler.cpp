#include "InputHandler.h"

namespace InputHandler {
    std::string getStringInput(const std::string& prompt) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    int getIntInput(const std::string& prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a number.\n";
                std::cin.clear();
                clearInputBuffer();
            } else {
                clearInputBuffer();
                return value;
            }
        }
    }

    void clearInputBuffer() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // kosongin buffer input setelah selesai pakai cin
    }
}