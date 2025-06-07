#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "ContactModel.h"
#include <vector>
#include <string>
using namespace std;

class Phonebook {
private:
    vector<Contact_Model> contacts;

public:
    void addContact(Contact_Model contact);
    vector<Contact_Model> getContacts();
    bool editContact(int contact_id, Contact_Model contact);
    bool deleteContact(int contact_id);
    bool isEmpty();
    vector<Contact_Model> searchContacts(string query);
    void outputContact();
    void saveContactsFile();
};

#endif // PHONEBOOK_H