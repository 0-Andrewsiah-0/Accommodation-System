#include <iostream>
#include "../others/utils.h"
#include "../classes/SearchingAlgorithm.h"
#include "../classes/DoublyLinkedList.h"

using namespace std;

struct adminFunction
{
    static void adminMenu(DoublyLinkedList<Admin> &adminList, DoublyLinkedList<Manager> &managerList, DoublyLinkedList<Tenant> &tenantList, DoublyLinkedList<Property> &propertyList)
    {
        int opt;
        do
        {
            cout << "========= Admin Menu =========" << endl;
            cout << "(1) Add New Manager User" << endl;
            cout << "(2) Modify Manager Status" << endl;
            cout << "(3) View Tenants' Details" << endl;
            cout << "(4) View Property Information" << endl;
            cout << "(5) Logout" << endl;
            cout << "Please select an option: ";
            cin >> opt;

            if (opt == 1)
            {
                createNewManager(managerList);
            }
            else if (opt == 2)
            {
                modifyManagerStatus(managerList);
            }
            else if (opt == 3)
            {
                displayTenantInformation(tenantList);
            }
            else if (opt == 4)
            {
                displayPropertyInformation(propertyList);
            }else if(opt == 5){
                return;
            }
        }while (opt != 5);
    }

    static void displayPropertyInformation(DoublyLinkedList<Property> &propertyList)
    {
        int opt;
        cout << "(1) Filter property price" << endl;
        cout << "(2) Filter property size" << endl;
        cout << "(3) Filter property room number" << endl;
        cout << "(4) Filter property type" << endl;
        cout << ">>";
        cin >> opt;

        if (opt == 1)
        {
            filterPropertyPrice(propertyList);
        }
        else if (opt == 2)
        {
            filterPropertySize(propertyList);
        }
        else if (opt == 3)
        {
            filterPropertyNumberRoom(propertyList);
        }
        else if (opt == 4)
        {
            filterPropertyType(propertyList);
        }
    }

    static void filterPropertyPrice(DoublyLinkedList<Property> &propertyList)
    {
        int choice;
        cout << "Please Select Your Budget" << endl;
        cout << endl;
        cout << "(1) More than RM 1500" << endl;
        cout << "(2) More than RM 2000" << endl;
        cout << "(3) less than RM 1500" << endl;
        cout << "(4) less than RM 2000" << endl;

        cout << ">>" << ends;
        cin >> choice;

        if (choice == 1)
        {
            linearSearchPropertyPriceMoreThan(propertyList.getHead(), 1500);
        }
        else if (choice == 2)
        {
            linearSearchPropertyPriceMoreThan(propertyList.getHead(), 2000);
        }
        else if (choice == 3)
        {
            linearSearchPropertyPriceLessThan(propertyList.getHead(), 1500);
        }
        else if (choice == 4)
        {
            linearSearchPropertyPriceLessThan(propertyList.getHead(), 2000);
        }
    }

    static void filterPropertyNumberRoom(DoublyLinkedList<Property> &propertyList)
    {
        int choice;
        cout << "Please Select Number of Room" << endl;
        cout << endl;
        cout << "(1) 1 room" << endl;
        cout << "(2) 2 room" << endl;
        cout << "(3) 3 room" << endl;
        cout << "(4) 4 room" << endl;
        cout << "(5) more than 4 room" << endl;

        cout << ">>" << ends;
        cin >> choice;

        if (choice == 1)
        {
            linearSearchPropertyRoomNumber(propertyList.getHead(), 1);
        }
        else if (choice == 2)
        {
            linearSearchPropertyRoomNumber(propertyList.getHead(), 2);
        }
        else if (choice == 3)
        {
            linearSearchPropertyRoomNumber(propertyList.getHead(), 3);
        }
        else if (choice == 4)
        {
            linearSearchPropertyRoomNumber(propertyList.getHead(), 4);
        }
        else if (choice == 5)
        {
            linearSearchPropertyRoomNumberMoreThan(propertyList.getHead(), 4);
        }
    }

    static void filterPropertyType(DoublyLinkedList<Property> &propertyList)
    {
        int choice;
            cout << "Please Select Property Type" << endl;
            cout << endl;
            cout << "(1) Apartment" << endl;
            cout << "(2) Service Residence" << endl;
            cout << "(3) Condominium " << endl;
            cout << "(4) Studio " << endl;
            cout << "(5) Flat " << endl;
            cout << "(6) Duplex " << endl;
            cout << "(7) Townhouse Condo " << endl;

            cout << ">>" << ends;
            cin >> choice;

            if (choice == 1)
            {
                linearSearchPropertyType(propertyList.getHead(), "Apartment");
            }
            else if (choice == 2)
            {
                linearSearchPropertyType(propertyList.getHead(), "Service Residence");
            }
            else if (choice == 3)
            {
                linearSearchPropertyType(propertyList.getHead(), "Condominium");
            }
            else if (choice == 4)
            {
                linearSearchPropertyType(propertyList.getHead(), "Studio");
            }
            else if (choice == 5)
            {
                linearSearchPropertyType(propertyList.getHead(), "Flat");
            }
            else if (choice == 6)
            {
                linearSearchPropertyType(propertyList.getHead(), "Duplex");
            }else if (choice == 7)
            {
                linearSearchPropertyType(propertyList.getHead(), "Townhouse Condo");
            }
    }

    static void filterPropertySize(DoublyLinkedList<Property> &propertyList)
    {
        int choice;
        cout << "Please Select Property Size" << endl;
        cout << endl;
        cout << "(1) More than 500 square feet" << endl;
        cout << "(2) More than 1000 square feet" << endl;
        cout << "(3) less than 500 square feet" << endl;
        cout << "(4) less than 1000 square feet" << endl;

        cout << ">>" << ends;
        cin >> choice;

        if (choice == 1)
        {
            linearSearchPropertySquareFeetMoreThan(propertyList.getHead(), 500);
        }
        else if (choice == 2)
        {
            linearSearchPropertySquareFeetMoreThan(propertyList.getHead(), 1000);
        }
        else if (choice == 3)
        {
            linearSearchPropertySquareFeetLessThan(propertyList.getHead(), 500);
        }
        else if (choice == 4)
        {
            linearSearchPropertySquareFeetLessThan(propertyList.getHead(), 1000);
        }
    }

    static void displayTenantInformation(DoublyLinkedList<Tenant> &tenantList)
    {
        int opt;
        cout << "(1) Filter Male Tenant" << endl;
        cout << "(2) Filter Female Tenant" << endl;
        cout << "(3) Filter Active Tenant" << endl;
        cout << "(4) Filter Inactive Tenant" << endl;
        cout << ">>";
        cin >> opt;

        if (opt == 1)
        {
            // male
            linearSearchGender(tenantList.getHead(), "male");
        }
        else if (opt == 2)
        {
            // female
            linearSearchGender(tenantList.getHead(), "female");
        }
        else if (opt == 3)
        {
            // active
            linearSearchStatus(tenantList.getHead(), true);
        }
        else if (opt == 4)
        {
            // inactive
            linearSearchStatus(tenantList.getHead(), false);
        }
    }

    static void modifyManagerStatus(DoublyLinkedList<Manager> &managerList)
    {
        managerList.showForward();
        string idModify, statusChange;
        bool status, success;
        cout << "Please enter manager id that u want to modify >>";
        cin >> idModify;
        cout << "Please enter status to change (Active/Inactive) >>";
        cin >> statusChange;

        if (utils::toLowerCase(statusChange) == "active")
        {
            status = true;
        }
        else if (utils::toLowerCase(statusChange) == "inactive")
        {
            status = false;
        }
        else
        {
            cout << "Error please enter status to change again" << endl;
        }

        success = managerList.findAndUpdateStatus(utils::toUpperCase(idModify), status);
        if (success)
        {
            cout << "Manager status has been modified successfully " << endl;
        }
        else
        {
            cout << "Something went wrong. Please try again" << endl;
        }
        managerList.showForward();
    }

    static void createNewManager(DoublyLinkedList<Manager> &managerList)
    {
        string tempUsername, tempPassword, tempGender;
        cout << "Enter New Manager username :" << ends;
        cin >> tempUsername;
        cout << "Enter New Manager password :" << ends;
        cin >> tempPassword;
        cout << "Enter New Manager gender :" << ends;
        cin >> tempGender;

        int largestid = managerList.findLargestId() + 1;

        Manager manager(largestid, tempUsername, tempPassword, tempGender, true);
        managerList.insertAtEnd(manager);
        cout << "New Manager has been created successfully." << endl;
        managerList.showForward();
    }
};
