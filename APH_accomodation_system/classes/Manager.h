#include <iostream>
#include "../others/utils.h"

using namespace std;

class Manager
{
public:
    int id;
    string username;
    string password;
    string gender;
    bool status;

    Manager(){}
    Manager(int id, string username, string password,string gender, bool status)
    {
        this->id = id;
        this->username = username;
        this->password = password;
        this->status = status;
        this->gender = gender;
    }

    ~Manager(){}

    int getId() { return this->id;}
    string getUsername() { return this->username; }
    string getPassword() { return this->password; }
    string getGender() { return this->gender; }
    bool getStatus() { return this->status; }
    void setId(int id) { this->id = id; }
    void setStatus(bool status) { this->status = status; }
    void setUsername(string username) { this->username = username; }
    void setPassword(string password) { this->password = password; }
    void setGender(string gender) { this->gender = gender; }


    friend std::ostream &operator<<(std::ostream &os, Manager &manager)
    {
        string statusDisplay;
        if (manager.status==true)
        {
            statusDisplay = "Active";
        }else{
            statusDisplay = "Inactive";
        }
        

        os <<"Manager ID: MN0"<<manager.id<<"\n"
            << "Username: " << manager.username << "\n"
           << "Password: " << manager.password << "\n"
           << "Gender : " <<utils::toUpperCase(manager.gender) << "\n"
           << "Status : " <<utils::toUpperCase(statusDisplay) << endl;
        return os;
    }
};
