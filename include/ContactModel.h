#ifndef CONTACT_MODEL_H
#define CONTACT_MODEL_H
#include <string>
using namespace std;

class Contact_Model {
private:
    int id;
    string name;
    string phone;
    static int next_id;

public:
    // Constructors
    Contact_Model();
    Contact_Model(string name, string phone);
    
    // Getter methods
    int getId() const;
    string getName() const;
    string getPhone() const;
    
    // Setter methods
    void setId(int id);
    void setName(const string& name);
    void setPhone(const string& phone);
    static void setNextID(int id);
};

#endif