#include "PhoneBook.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void Phonebook::addContact(Contact_Model contact) {
    contacts.push_back(contact);
    cout << "Contact successfully added!\n";
}

vector<Contact_Model> Phonebook::getContacts() {
    return contacts;
}

bool Phonebook::editContact(int contact_id, Contact_Model contact) {
    for (auto& existingContact : contacts) {
        if (existingContact.getId() == contact_id) {
            existingContact.setName(contact.getName());
            existingContact.setPhone(contact.getPhone());
            cout << "Contact successfully updated!\n";
            return true;
        }
    }
    cout << "Contact with ID " << contact_id << " not found!\n";
    return false;
}

bool Phonebook::deleteContact(int contact_id) {
    auto it = remove_if(contacts.begin(), contacts.end(),
                        [&contact_id](const Contact_Model& contact) {
                            return contact.getId() == contact_id;
                        });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact successfully deleted!\n";
        return true;
    }
    cout << "Contact with ID " << contact_id << " not found!\n";
    return false;
}

bool Phonebook::isEmpty() {
    return contacts.empty();
}

vector<Contact_Model> Phonebook::searchContacts(string query) {
    vector<Contact_Model> results;
    string lowerQuery = toLower(query);

    for (const auto& contact : contacts) {
        if (toLower(contact.getName()).find(lowerQuery) != string::npos ||
            contact.getPhone().find(query) != string::npos) {
            results.push_back(contact);
        }
    }

    return results;
}

void Phonebook::outputContact() {
    if (isEmpty()) {
        cout << "No contacts in phonebook.\n";
        return;
    }

    cout << "\n=== ALL CONTACTS LIST ===\n";
    for (size_t i = 0; i < contacts.size(); i++) {
        cout << "\nContact " << (i + 1) << ":\n";
        cout << "ID: " << contacts[i].getId() << "\n";
        cout << "Name: " << contacts[i].getName() << "\n";
        cout << "Phone: " << contacts[i].getPhone() << "\n";
        cout << "-------------------------\n";
    }
}