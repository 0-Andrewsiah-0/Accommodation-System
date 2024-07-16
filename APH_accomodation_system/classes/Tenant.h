#include <iostream>
#include "../others/utils.h"
#include "../classes/DoublyLinkedList.h"


using namespace std;

class Tenant
{
public:
    int id;
    string username;
    string password;
    string gender;
    bool status = true;

    static DoublyLinkedList<Tenant> tenantList;

    Tenant(){}

    Tenant(int id, string username, string password, string gender,bool status = true)
    {
        this->id = id;
        this->username = username;
        this->password = password;
        this->gender = gender;
        this->status = status;
    }

    ~Tenant(){}

    int getId(){ return this->id; }
    string getUsername() { return this->username; }
    string getPassword() { return this->password; }
    string getGender() { return this->gender; }
    bool getStatus() { return this->status; }
    void setId(int id) { this->id = id; }
    void setStatus(bool status) { this->status = status; }
    void setUsername(string username) { this->username = username; }
    void setPassword(string password) { this->password = password; }
    void setGender(string gender) { this->gender = gender; }

    friend std::ostream& operator<<(std::ostream& os, Tenant& tenant)
    {
        string statusDisplay;
        if (tenant.status == true)
        {
            statusDisplay = "ACTIVE";
        }
        else
        {
            statusDisplay = "INACTIVE";
        }

        os << "Tenant ID: TN0"<<tenant.id<<"\n"
           << "Username : " << tenant.username << "\n"
           << "Password : " << tenant.password << "\n"
           << "Gender : " << utils::toUpperCase(tenant.gender) << "\n"
           << "Status : " << utils::toUpperCase(statusDisplay) << endl;
        return os;
    }
  
};

// DoublyLinkedList<Tenant> Tenant::tenantList;