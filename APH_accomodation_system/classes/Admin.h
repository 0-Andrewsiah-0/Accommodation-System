#include <iostream>
#include "../others/utils.h"
#include "DoublyLinkedList.h"

using namespace std;

class Admin
{
public:
    int id;
    string username;
    string password;
    string gender;
    bool status =true;

    Admin(){}

    Admin(int id ,string username, string password ,string gender, bool status=true)
    {
        this->id = id;
        this->username = username;
        this->password = password;
        this->status = status;
        this->gender = gender;
    }

    ~Admin(){}

    int getId(){return this->id;}
    string getUsername() { return this->username; }
    string getPassword() { return this->password; }
    bool getStatus() { return this->status; }
    string getGender() { return this->gender; }
    void setStatus(bool status) { this->status = status; }
    void setUsername(string username) { this->username = username; }
    void setPassword(string password) { this->password = password; }
    void setGenders(string genders) { this->gender =genders; }
    void setId(int id) {this->id = id;}

    // This function is necessary to print the object's data in showForward function
    friend std::ostream& operator<<(std::ostream& os, Admin& admin) {
        string statusDisplay;
        if (admin.status==true)
        {
            statusDisplay = "Active";
        }else{
            statusDisplay = "Inactive";
        }
        

        os << "Admin ID: AD0" << admin.id << "\n"
            << "Username: " << admin.username << "\n"
           << "Password: " << admin.password << "\n"
           << "Gender : " <<utils::toUpperCase(admin.gender) << "\n"
           << "Status : " <<utils::toUpperCase(statusDisplay) << endl;
        return os;
    }
};
