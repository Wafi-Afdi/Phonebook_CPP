#include "StateMachine.h"
#include "MainMenuState.h"
#include <iostream>

StateMachine::StateMachine()
{
    running = true;
    transitionTo(std::make_unique<MainMenuState>()); // mulai dengan main menu
}

void StateMachine::run()
{
    while (running)
    {
        if (currentState)
        {
            currentState->enter();
            currentState->display();
            std::unique_ptr<State> nextState = currentState->handleInput(phonebook);

            if (nextState)
            {
                transitionTo(std::move(nextState));
            }
            else
            {
                running = false;
            }
        }
    }
    std::cout << "Exiting Phonebook application. Goodbye!\n";
}

void StateMachine::transitionTo(std::unique_ptr<State> newState)
{
    currentState = std::move(newState);
}

bool StateMachine::parseFromFile(std::string filepath)
{
    std::ifstream file(filepath);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
        return false;
    }


        
    int new_next_id = 1;
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string segment;

        int id = 0;
        std::string name;
        std::string phone;

        // Parse ID
        if (std::getline(ss, segment, ';'))
        {
            try
            {
                id = std::stoi(segment);
                if(new_next_id <= id + 1) {
                    new_next_id = id + 1;
                }
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "Warning: Invalid ID format in line: " << line << std::endl;
                continue;
            }
            catch (const std::out_of_range &e)
            {
                std::cerr << "Warning: ID out of range in line: " << line << std::endl;
                continue;
            }
        }
        else
        {
            std::cerr << "Warning: Missing ID in line: " << line << std::endl;
            continue;
        }

        // Parse Name
        if (std::getline(ss, segment, ';'))
        {
            name = segment;
        }
        else
        {
            std::cerr << "Warning: Missing name in line: " << line << std::endl;
            continue;
        }

        // Parse Phone
        if (std::getline(ss, segment))
        { // Read until end of line for the last segment
            phone = segment;
        }
        else
        {
            std::cerr << "Warning: Missing phone number in line: " << line << std::endl;
            continue;
        }

        // Create Contact_Model and add to Phonebook
        Contact_Model contact(name, phone);
        contact.setId(id);
        phonebook.addContact(contact);
    }

    Contact_Model::setNextID(new_next_id);

    file.close();
    return true;
}
