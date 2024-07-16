#include <iostream>
#include "../classes/DoublyLinkedList.h"
#include "../others/utils.h"
#include "../Views/adminFunction.h"
#include "../Views/managerFunction.h"
#include "../Views/tenantFunction.h"

using namespace std;

struct Menu
{
    static void displayMenu(DoublyLinkedList<Admin> &adminList, DoublyLinkedList<Manager> &managerList, DoublyLinkedList<Tenant> &tenantList, DoublyLinkedList<Property> &propertyList, DoublyLinkedList<Property> &favouriteListAll, DoublyLinkedList<Property> &favouriteListTenant, Queue<Property>& rentRequestList, Queue<Property>& rentingHistoryList)
    {
        while (true)
        {
            int input;

            cout << endl;
            cout << "    WELCOME TO ASIA PACIFIC HOME(APH)   " << endl;
            cout << "_________________________________________" << endl;
            cout << "(1) Register As Tenant " << endl;
            cout << "(2) Login " << endl;
            cout << "(3) Display Property " << endl;
            cout << "(4) Exit " << endl;
            cout << endl;
            cout << "Please enter your selection >> " << ends;
            cin >> input;


            if(input == 1) {
                tenantList = tenantRegister(tenantList);
            }
            else if (input == 2)
            {
                userSelection(adminList, managerList, tenantList, propertyList, favouriteListAll, favouriteListTenant, rentRequestList, rentingHistoryList);
            }
            else if (input == 3)
            {
                cout << "display" << endl;
                propertyList.showForward(5);
            }
            else if (input == 4)
            {
                if (utils::exitFunction())
                {
                    break;
                }
            }
            else
            {
                cout << "Please enter a valid choice !" << endl;
            }
        }
    }

    static void userSelection(DoublyLinkedList<Admin> &adminList, DoublyLinkedList<Manager> &managerList, DoublyLinkedList<Tenant> &tenantList, DoublyLinkedList<Property> &propertyList, DoublyLinkedList<Property> &favouriteListAll, DoublyLinkedList<Property> &favouriteListTenant, Queue<Property>& rentRequestList, Queue<Property>& rentingHistoryList)
    {
        int input;

        cout << endl;
        cout << "(1) Tenant  " << endl;
        cout << "(2) Manager " << endl;
        cout << "(3) Admin " << endl;
        cout << "(4) Back " << endl;

        cout << endl;
        cout << "Please enter your account to login : " << ends;
        cin >> input;

        if (input == 1)
        {
            // tenent function
            bool isTenant;
            const string tempUsername = utils::askUserUsername();
            const string tempPassword = utils::askUserPassword();

            isTenant = tenantList.find(utils::toLowerCase(tempUsername), utils::toLowerCase(tempPassword));
            if (isTenant)
            {
                cout << "Welcome " << utils::toUpperCase(tempUsername) << "!" << endl;
                 // tenant function
                tenantFunction::tenantMenu(adminList, managerList, tenantList, propertyList, favouriteListAll, favouriteListTenant, rentRequestList, rentingHistoryList);
            }
            else
            {
                cout << "Invalid username or password !" << endl;
                displayMenu(adminList, managerList, tenantList, propertyList, favouriteListAll, favouriteListTenant, rentRequestList, rentingHistoryList);
            }
        }
        else if (input == 2)
        {
            // manager function
            bool isManager;
            const string tempUsername = utils::askUserUsername();
            const string tempPassword = utils::askUserPassword();

            isManager = managerList.find(utils::toLowerCase(tempUsername), utils::toLowerCase(tempPassword));
            if (isManager)
            {
                cout << "Welcome " << utils::toUpperCase(tempUsername) << "!" << endl;
                // manager function
                managerFunction::managerMenu(adminList, managerList, tenantList, propertyList, favouriteListAll, rentRequestList, rentingHistoryList);
            }
            else
            {
                cout << "Invalid username or password !" << endl;
                displayMenu(adminList, managerList, tenantList, propertyList, favouriteListAll, favouriteListTenant, rentRequestList, rentingHistoryList);
            }
        }
        else if (input == 3)
        {
            // admin function
            bool isAdmin;
            const string tempUsername = utils::askUserUsername();
            const string tempPassword = utils::askUserPassword();

            isAdmin = adminList.find(utils::toLowerCase(tempUsername), utils::toLowerCase(tempPassword));
            if (isAdmin)
            {
                cout << "Welcome " << utils::toUpperCase(tempUsername) << "!" << endl;
                //    Admin function
                adminFunction::adminMenu(adminList, managerList, tenantList, propertyList);
            }
            else
            {
                cout << "Invalid username or password !" << endl;
                displayMenu(adminList, managerList, tenantList, propertyList, favouriteListAll, favouriteListTenant, rentRequestList, rentingHistoryList);
            }
        }

        else if (input == 4)
        {
            displayMenu(adminList, managerList, tenantList, propertyList, favouriteListAll, favouriteListTenant, rentRequestList, rentingHistoryList);
        }
    }

    static bool exitFunction()
    {
        char input;
        cout << "Are u sure to exit ? (y/n)" << endl;
        cout << ">>";
        cin >> input;
        if (utils::toLowerCase(input) == "y")
        {
            exit(0);
            cout << "Thank You For Using  ASIA PACIFIC HOME ." << endl;
        }
        else if (utils::toLowerCase(input) == "n")
        {
            return true;
        }
    }

    static DoublyLinkedList<Tenant> tenantRegister(DoublyLinkedList<Tenant> &tenantList) {
        int newId = tenantList.getSize() + 1;
        string newUsername;
        string newPassword;
        string newGender;
        bool newStatus = true;

        cout << "Please enter username for registration: ";
        cin >> newUsername;
        cout << "Please enter password for registration: ";
        cin >> newPassword;
        cout << "Please enter gender for registration: ";
        cin >> newGender;

        Tenant newTenant(newId, newUsername, newPassword, newGender, newStatus);

        tenantList.insertAtEnd(newTenant);

        cout << "New tenant is registered successfully" << endl;

        return tenantList;

    }


};
