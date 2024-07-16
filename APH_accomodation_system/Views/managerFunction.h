#include <iostream>
#include "../others/utils.h"
#include <string>
#include "../classes/SearchingAlgorithm.h"
#include "../classes/DoublyLinkedList.h"
#include "map"
#include "../classes/Queue.h"
#include <regex>
// #include "../classes/Tenant.h"
// #include "../classes/SortingAlgorithm.h"

using namespace std;

struct managerFunction
{
    static void managerMenu(DoublyLinkedList<Admin> &adminList, DoublyLinkedList<Manager> &managerList, DoublyLinkedList<Tenant> &tenantList, DoublyLinkedList<Property> &propertyList, DoublyLinkedList<Property> &favouriteListAll, Queue<Property> &rentRequestList, Queue<Property> &rentingHistoryList)
    {
        int choice;
        do
        {
            cout << "\n======== Manager Menu ========" << endl;
            cout << "(1) Display All Tenant's Details" << endl;
            cout << "(2) Search Tenant Details" << endl;           // linearsearch
            cout << "(3) Delete Inactive Tenant Accounts" << endl; 
            cout << "(4) Generate Top 10 Property Report" << endl; // sort
            cout << "(5) Manage Tenancy Process" << endl;          // show rent request ,show pending list, approve and reject.
            cout << "(6) Manage Payment" << endl;                  // approve, show receipt
            cout << "(0) Logout" << endl;
            cout << "\nPlease enter your choice (1-6): ";
            cin >> choice;

            if (choice == 1)
            {
                displayRegisteredTenant(tenantList);
            }
            else if (choice == 2)
            {
                searchTenant(tenantList);
            }
            else if (choice == 3)
            {
                deleteInactiveTenant(tenantList);
            }
            else if (choice == 4)
            {
                generateTop10PropertyReport(propertyList, favouriteListAll, favouriteListAll.getHead());
            }
            else if (choice == 5)
            {
                manageTenancyProcess(tenantList, rentRequestList, rentingHistoryList);
            }
            else if (choice == 6)
            {
                // Manage payment of the confirmed tenancy
                cout << "\n-----* Manage Payment *-----" << endl;
                managePayment(tenantList, rentRequestList, rentingHistoryList);
            }
            else if (choice == 0)
            {
                cout << "Exiting Manager Menu..." << endl;
                break;
            }
        } while (choice != 0);
    }

    // -------------------------------------------------------------------------------------------------------------------------

    static void displayRegisteredTenant(DoublyLinkedList<Tenant> &tenantList)
    {
        // Display all registered tenant details
        cout << "\n-----* All Registered Tenant's Details *------" << endl;
        tenantList.showForward();
    }

    static void searchTenant(DoublyLinkedList<Tenant> &tenantList)
    {
        // Search Tenant Details
        cout << "\n-----* Search Tenant Details *-----" << endl;
        tenantList.showForward();
        cout << "Search Tenant ID: ";
        string ID;
        cin >> ID;
        regex idPattern("(tn|TN)\\d{2}");
        if (!regex_match(ID, idPattern))
        {
            cout << "Invalid input. Please enter a valid Tenant ID (e.g., TN01)." << endl;
            return; // Exit the function or handle the invalid input appropriately
        }
        int intIdSearch = stoi(ID.substr(2));
        Tenant *searchTenant = linearSearchId<Tenant>(tenantList.getHead(), intIdSearch);
        if (searchTenant != nullptr)
        {
            // Display the details of the found tenant
            cout << "\nTenant Details:" << endl;
            cout << "Tenant ID: TN0" << searchTenant->getId() << endl;
            cout << "Username: " << searchTenant->getUsername() << endl;
            cout << "Password: " << searchTenant->getPassword() << endl;
            cout << "Gender: " << utils::toUpperCase(searchTenant->getGender()) << endl;
            cout << "Status: " << (searchTenant->getStatus() ? "ACTIVE" : "INACTIVE") << endl;
        }
        else
        {
            cout << "Tenant not found." << endl;
        }
    }

    static void deleteInactiveTenant(DoublyLinkedList<Tenant> &tenantList)
    {
        // Delete tenant accounts based on inactivity status
        cout << "\n-----* Delete Inactive Tenant Accounts *-----" << endl;
        cout << "\n---- All Inactive Tenant ----- " << endl;
        linearSearchStatus(tenantList.getHead(), false);
        cout << "\nEnter the tenant ID to delete (TN00): " << endl;
        string ID;
        cin >> ID;
        regex idPattern("(tn|TN)\\d{2}");
        if (!regex_match(ID, idPattern))
        {
            cout << "Invalid input. Please enter a valid Tenant ID (e.g., TN01)." << endl;
            return; // Exit the function or handle the invalid input appropriately
        }
        int intId = stoi(ID.substr(2)); // Convert ID from string to int
        DoublyNode<Tenant> *searchNode = linearSearchDelete(tenantList.getHead(), intId);
        if (searchNode != nullptr)
        {
            tenantList.deleteNode(searchNode);
            cout << "\nTenant with ID " << ID << " successfully deleted from the list." << endl;
            cout << "\n----### Updated Tenant List ###----" << endl;
            tenantList.showForward();
        }
        else
        {
            cout << "\nTenant not found." << endl;
        }
    }

    static void generateTop10PropertyReport(DoublyLinkedList<Property> &propertyList, DoublyLinkedList<Property> &favouriteListAll, DoublyNode<Property> *head)
    {
        cout << "----- Top 10 Property Report -----\n"
             << endl;

        /// Determine the number of properties in the favouriteListAll
        int numProperties = favouriteListAll.getSize();
        cout << "Number of properties in favouriteListAll: " << numProperties << endl;
        cout << "\n ";

        map<string, int> propertyCount;
        map<string, string> propertyNameCount;
        map<string, string> propertyLocation;
        map<string, string> propertyType;

        DoublyNode<Property> *temp = head;
        while (temp != nullptr)
        {
            propertyCount[temp->data.getID()]++;
            propertyNameCount[temp->data.getID()] = temp->data.getPropname();
            propertyLocation[temp->data.getID()] = temp->data.getLocation();
            propertyType[temp->data.getID()] = temp->data.getPropertyType();
            temp = temp->next;
        }

        cout << "----- Top 10 Property Rank from Tenant Favourite List -----\n";

        // Find the top 10 properties based on occurrence count
        for (int count = 1; count <= 10; count++)
        {
            int maxOccurrence = 0;
            string topProperty;
            for (const auto &pair : propertyCount)
            {
                if (pair.second > maxOccurrence)
                {
                    maxOccurrence = pair.second;
                    topProperty = pair.first;
                }
            }

            if (maxOccurrence > 0)
            {
                cout << "Top " << count << " :" << propertyNameCount[topProperty] << endl;
                cout << "Property ID: " << topProperty << endl;
                cout << "Occurrences Count: " << maxOccurrence << endl;
                propertyCount.erase(topProperty); // important code, it function for erase the highest count after it list to display

                // // Display property location and type
                cout << "Location: ";
                auto locationPair = propertyLocation.find(topProperty);
                if (locationPair != propertyLocation.end())
                {
                    cout << locationPair->second << endl;
                }
                else
                {
                    cout << "Unknown" << endl;
                }

                cout << "Property Type: ";
                auto typePair = propertyType.find(topProperty);
                if (typePair != propertyType.end())
                {
                    cout << typePair->second << endl;
                }
                else
                {
                    cout << "Unknown" << endl;
                }

                cout << "------------------------" << endl;
            }
            else
            {
                break; // No more properties with occurrences to display
            }
        }
    }

    static void manageTenancyProcess(DoublyLinkedList<Tenant> &tenantList, Queue<Property> &rentRequestList, Queue<Property> &rentingHistoryList)
    {
        // Manage Tenancy Process upon renting request received.
        cout << "\n-----* Manage Tenancy Process *-----" << endl;
        cout << "----- Current Rent Request List -----\n" << endl;
        rentRequestList.display(); // Display the current rent request list

        while (!rentRequestList.isEmpty())
        {
            Property property = rentRequestList.peek();
            rentRequestList.dequeue();

            string tenancyProgress;
            cout << "\nEnter 'a' to approve or 'r' to reject the tenancy progress for Property ID: " << property.getID() << ": ";
            cin >> tenancyProgress;
            if (tenancyProgress == "a" || tenancyProgress == "A")
            {
                property.setTenancyProgress(tenancyProgress);
                cout << "\nProperty " << (tenancyProgress == "a" || tenancyProgress == "A" ? "Approved" : "Rejected") << "! Property rent successfully. \n" << endl;
                rentingHistoryList.enqueue(property);
            }else if (tenancyProgress == "r" || tenancyProgress == "R") {
                property.setTenancyProgress(tenancyProgress);
                cout << "\nProperty Rejected! Property not available to rent. \n" << endl;
                rentingHistoryList.enqueue(property);
            }else
            {
                cout << "Invalid input. Tenancy progress remains as 'pending'." << endl;
            }
            cout << "\n----- Updated Renting List -----\n" << endl;
            rentingHistoryList.display();
            rentRequestList.display();
        }
    }

    static void managePayment(DoublyLinkedList<Tenant> &tenantList, Queue<Property> &rentRequestList, Queue<Property> &rentingHistoryList)
    {
        cout << "----- Current Renting List -----\n" << endl;
        rentingHistoryList.display();

        while (!rentingHistoryList.isEmpty())
        {
            Property property = rentingHistoryList.peek();
            rentingHistoryList.dequeue();
            string tenancyProgress = property.getTenancyProgress();

            if (tenancyProgress == "Approved" || tenancyProgress == "APPROVED")
            {
                cout << "Confirm to accept the payment for Property ID: " << property.getID() << "? (y/n): ";
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    property.setTenancyProgress("active");
                    rentingHistoryList.enqueue(property);
                    cout << "\nPayment accepted for Property ID: " << property.getID() << ". Tenancy progress updated to Active.\n" << endl;
                }else if (choice == 'n' || choice == 'N')
                {
                    property.setTenancyProgress("approved");
                    rentingHistoryList.enqueue(property);
                    cout << "\nPayment for Property ID: " << property.getID() << " not accepted. Tenancy progress remains Approved.\n" << endl;
                }else
                {
                    cout << "\n Invalid Input. Tenancy progress no update.\n" << endl;
                }
            }
            else if (tenancyProgress == "Rejected" || tenancyProgress == "REJECTED")
            {
                cout << "Confirm to refund the payment for Property ID: " << property.getID() << "? (y/n): ";
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    property.setTenancyProgress("refund");
                    rentingHistoryList.enqueue(property);
                    cout << "\nPayment ready to refund, Tenancy progress updated to Refund.\n" << endl;
                }else if (choice == 'n' || choice == 'N')
                {
                    property.setTenancyProgress("rejected");
                    rentingHistoryList.enqueue(property);
                    cout << "\nPayment for Property ID: " << property.getID() << " not refunded. Tenancy progress remains Rejected.\n" << endl;
                }else
                {
                    cout << "\n Invalid Input. Tenancy progress no update.\n" << endl;
                }
            }
            else
            {
                break;
            }
            rentingHistoryList.display();
        }
    }
};

