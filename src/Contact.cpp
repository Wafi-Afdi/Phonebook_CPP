#include "ContactModel.h"

// Initialize static variable
int Contact_Model::next_id = 1;

void Contact_Model::setNextID(int id) {
    next_id = id;
}

// Default constructor
Contact_Model::Contact_Model() : id(next_id++), name(""), phone("") {}

// Parameterized constructor
Contact_Model::Contact_Model(string name, string phone) 
    : id(next_id++), name(name), phone(phone) {}

// Getter methods
int Contact_Model::getId() const { 
    return id; 
}

string Contact_Model::getName() const { 
    return name; 
}

string Contact_Model::getPhone() const { 
    return phone; 
}

// Setter methods
void Contact_Model::setId(int id) { 
    this->id = id; 
}

void Contact_Model::setName(const string& name) { 
    this->name = name; 
}

void Contact_Model::setPhone(const string& phone) { 
    this->phone = phone; 
}