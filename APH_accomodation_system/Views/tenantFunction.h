#include <iostream>
#include "../others/utils.h"
#include "../classes/SortingAlgorithm.h"
#include "../classes/SearchingAlgorithm.h"
#include "../classes/DoublyLinkedList.h"
#include <chrono>
#include "../others/extractcsv.h"
#include <bits/stdc++.h>
#include <string>

using namespace std;

using namespace std::chrono;

struct tenantFunction{
    static void tenantMenu(DoublyLinkedList<Admin> &adminList, DoublyLinkedList<Manager> &managerList, DoublyLinkedList<Tenant> &tenantList, DoublyLinkedList<Property> &propertyList, DoublyLinkedList<Property> &favouriteListAll, DoublyLinkedList<Property> &favouriteListTenant, Queue<Property>& rentRequestList, Queue<Property>& rentingHistoryList){

        int choice;
        do
        {
        cout << "\n======== Tenant Menu ========" << endl;
        cout << "(1) Sort Property" << endl;
        cout << "(2) Add Favourite Property" << endl;
        cout << "(3) Request Rent from Favourite Property" << endl;
        cout << "(4) Display Rent History" << endl;
        cout << "(5) Search Property" << endl;
        cout << "(6) Logout" << endl;
        cout << "\nPlease select a function (1-6): ";
        cin >> choice;

        if (choice==1){
            // sorting function
            sortFunction(propertyList);
        }
        else if (choice==2){
            addfavlistFunction(propertyList, favouriteListAll, favouriteListTenant);
        }
        else if (choice==3){
            rentRequestFunction(favouriteListTenant, rentRequestList);
        }
        else if (choice==4){
            showRentHistory(rentingHistoryList); 
        }
        else if (choice==5){
            searchMenu(propertyList);
            
        }
        else if (choice==6){
            cout << "Exiting Tenant Menu..." << endl;
            break;
        }
        } while (choice != 0);
    }

    static void sortFunction(DoublyLinkedList<Property> &propertyList){
        int selection;
        // select which property information to sort
        cout << "\n-----* Property Sorting *------" << endl;
        cout << "(1) Sort By Monthly Rent" << endl;
        cout << "(2) Sort By Property Size" << endl;
        cout << "(3) Sort By Location" << endl;
        cout << "(4) Test Sort Speed" << endl;
        cout << "\nPlease Enter Your Selection: (1-4): ";
        cin >> selection;
        cout << endl;
        cout << endl;

        //select ascending or decending sorting order
        if (selection==1){
            int sortOrder;
            cout << "\n-----* Sorting Order *------" << endl;
            cout << "(1) Sort By Ascending Order" << endl;
            cout << "(2) Sort By Decending Order" << endl;
            cout << "(3) Back" << endl;
            cout << "\nPlease Enter Your Selection: (1-3): ";
            cin >> sortOrder;
            if (sortOrder==1){
                cout << "Sorting in Progress..." << endl;
                // bubbleSort(propertyList, "monthlyRent", true);
                quickSorts(propertyList, "monthlyRent", true);
                propertyList.showForward(5);
            } else if (sortOrder==2){
                cout << "Sorting in Progress..." << endl;
                // bubbleSort(propertyList, "monthlyRent", false);
                quickSorts(propertyList, "monthlyRent", false);
                propertyList.showForward(5);
            } else if (sortOrder==3){
                sortFunction(propertyList);
            } 
            else {
                cout << "\nInvalid selection, Try Again!" << endl;
            }
        }
        if (selection==2){
            int sortOrder;
            cout << "(1) Sort By Ascending Order" << endl;
            cout << "(2) Sort By Decending Order" << endl;
            cout << "(3) Back" << endl;
            cout << "\nPlease Enter Your Selection: (1-3): ";
            cin >> sortOrder;
            if (sortOrder==1){
                cout << "Sorting in Progress..." << endl;
                // bubbleSort(propertyList, "size", true);
                quickSorts(propertyList, "size", true);
                propertyList.showForward(5);
            } else if (sortOrder==2){
                cout << "Sorting in Progress..." << endl;
                // bubbleSort(propertyList, "size", false);
                quickSorts(propertyList, "size", false);
                propertyList.showForward(5);
            } else {
                cout << "\nInvalid selection, Try Again!" << endl;
                sortFunction(propertyList);
            }
        }
        if (selection==3){
            int sortOrder;
            cout << "(1) Sort By Ascending Order" << endl;
            cout << "(2) Sort By Decending Order" << endl;
            cout << "(3) Back" << endl;
            cout << "\nPlease Enter Your Selection: (1-3): ";
            cin >> sortOrder;
            if (sortOrder==1){
                cout << "Sorting in Progress..." << endl;
                // bubbleSort(propertyList, "location", true);
                quickSorts(propertyList, "location", true);
                propertyList.showForward(5);
            } else if (sortOrder==2){
                cout << "Sorting in Progress..." << endl;
                // bubbleSort(propertyList, "location", false);
                quickSorts(propertyList, "location", false);
                propertyList.showForward(5);
            } else {
                cout << "\nInvalid selection, Try Again!" << endl;
                sortFunction(propertyList);
            }
        }
        if (selection==4){ // compare time taken for both sorting algorithms to sort by monthlyRent in decending order
            int test;
            cout << "(1) Bubble Sort Monthly Rent" << endl;
            cout << "(2) Quick Sort Monthly Rent" << endl;
            cout << "\nTest Sorting Speed for?: (1-2): ";
            cin >> test;
            
            if (test==1){
                propertyList = initializeProperty();
                cout << "Sorting in Progress..." << endl;
                auto start = chrono::high_resolution_clock::now();

                // Call the quicksort function
                bubbleSort(propertyList, "monthlyRent", false);

                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
                cout << "Time taken by bubble sort: "
                    << duration.count() << " seconds" << endl;
            } else if (test==2){
                propertyList = initializeProperty();
                cout << "Sorting in Progress..." << endl;
                auto start = chrono::high_resolution_clock::now();

                // Call the bubble sort function
                quickSorts(propertyList, "monthlyRent", false);

                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
                cout << "Time taken by quick sort: "
                    << duration.count() << " seconds" << endl;
            } else {
                cout << "\nInvalid selection, Try Again!" << endl;
                sortFunction(propertyList);
            }
        }
    }

    static void addfavlistFunction(DoublyLinkedList<Property> &propertyList, DoublyLinkedList<Property> &favouriteListAll, DoublyLinkedList<Property> &favouriteListTenant){
        int id;
        cout << "\n-----* Add to Favourite *------" << endl;
        cout << "Please Enter ID of Property: " << endl;
        cin >> id;

    DoublyNode<Property> *temp = propertyList.getHead();
    while (temp != nullptr)
    {
        if (temp->data.getID() == std::to_string(id))
        {
            favouriteListAll.insertAtbeginning(temp->data);
            // Only insert into favouriteListTenant if not duplicate
            bool existsInTenant = false;
            DoublyNode<Property> *tenantTemp = favouriteListTenant.getHead();
            while (tenantTemp != nullptr)
            {
                if (tenantTemp->data.getID() == std::to_string(id))
                {
                    existsInTenant = true;
                    break;
                }
                tenantTemp = tenantTemp->next;
            }

            if (!existsInTenant)
            {
                favouriteListTenant.insertAtbeginning(temp->data);
                cout << "Property Added to Tenant Favourite List" << endl;
            }
            cout << "Property Added to Favourite List" << endl;
            return; // Property found and added, exit the function
        }
        temp = temp->next;
    }

    // If loop completes, property was not found
    cout << "Property not found" << endl;

    }

    static void searchMenu(DoublyLinkedList<Property> &propertyList) {

        int searchMenuChoice;

        cout << "\n======== Search Menu ========" << endl;
        cout << "(1) Search and Display Property Details" << endl;
        cout << "(2) Search Algorithm Execution Time Testing" << endl;
        cout << "(3) Back" << endl;
        cout << "\nPlease enter your choice (1-3): ";

        cin >> searchMenuChoice;

        if(searchMenuChoice == 1){
            searchFunction1(propertyList);
        }

        if(searchMenuChoice == 2){
            searchFunction2(propertyList);
        }


    }

    static void searchFunction1(DoublyLinkedList<Property> &propertyList){
        
        int searchChoice;

        cout << "\n======== Search Menu ========" << endl;
        cout << "(1) Number of Rooms" << endl;
        cout << "(2) Number of Bathrooms" << endl;
        cout << "(3) Property Type" << endl;
        cout << "(4) Region" << endl;
        cout << "(5) Back" << endl;
        cout << "\nPlease enter your choice (1-5): ";

        cin >> searchChoice;

        if(searchChoice == 1){
            DoublyLinkedList<Property> linearSearchPropertyList;
            DoublyLinkedList<Property> binarySearchPropertyList;

            linearSearchPropertyList = propertyList;
            binarySearchPropertyList = propertyList;

            int tempRooms;
            cout << "Please type the number of rooms: " ;
            cin >> tempRooms;

            int roomRange;
            cout << endl << "Lower than equal to " << tempRooms << " or higher than equal to " << tempRooms << " (Please type 0 for lower than equal to or 1 for higher than equal to) : " ;
            cin >> roomRange;

            bool found = false;

            // For Linear Search

            cout << "*DISPLAY OF 10 RELEVANT PROPERTIES* " << endl << endl;

            DoublyNode<Property> *temp = linearSearchPropertyList.head;
            int count = 0;


            while (temp != nullptr && count < 10) {
                string strRooms = temp->data.getRooms();
                if(roomRange == 0) {
                    if (strRooms <= to_string(tempRooms))
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }
                }

                if(roomRange == 1) {
                    if (strRooms >= to_string(tempRooms))
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }
                }

                temp = temp->next;

            }

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl << endl;
            }

        }

        if(searchChoice == 2){
            DoublyLinkedList<Property> linearSearchPropertyList;
            DoublyLinkedList<Property> binarySearchPropertyList;

            linearSearchPropertyList = propertyList;
            binarySearchPropertyList = propertyList;

            int tempBathrooms;
            cout << "Please type the number of bathrooms: " ;
            cin >> tempBathrooms;

            int bathRoomRange;
            cout << endl << "Lower than equal to " << tempBathrooms << " or higher than equal to " << tempBathrooms << " (Please type 0 for lower than equal to or 1 for higher than equal to) : " ;
            cin >> bathRoomRange;

            bool found = false;

            // For Linear Search

            cout << "*DISPLAY OF 10 RELEVANT PROPERTIES* " << endl << endl;

            DoublyNode<Property> *temp = linearSearchPropertyList.head;
            int count = 0;


            while (temp != nullptr && count < 10) {
                string strBathrooms = temp->data.getBathrooms();

                if(bathRoomRange == 0) {
                    if (strBathrooms <= to_string(tempBathrooms))
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }
                }

                if(bathRoomRange == 1) {
                    if (strBathrooms >= to_string(tempBathrooms))
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }
                }

                temp = temp->next;
            }

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl << endl;
            }

        }

        if(searchChoice == 3){
            DoublyLinkedList<Property> linearSearchPropertyList;
            DoublyLinkedList<Property> binarySearchPropertyList;

            linearSearchPropertyList = propertyList;
            binarySearchPropertyList = propertyList;

            cin.ignore();

            string tempPropertyType;
            cout << "Please type the property type: " ;
            getline(cin, tempPropertyType);

            

            bool found = false;

            // For Linear Search

            cout << "*DISPLAY OF 10 RELEVANT PROPERTIES* " << endl << endl;

            DoublyNode<Property> *temp = linearSearchPropertyList.head;
            int count = 0;


            while (temp != nullptr && count < 10) {
                string strPropertyType = temp->data.getPropertyType();

                if (strPropertyType == tempPropertyType)
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }

                temp = temp->next;
            }

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl << endl;
            }

        }

        if(searchChoice == 4){
            DoublyLinkedList<Property> linearSearchPropertyList;
            DoublyLinkedList<Property> binarySearchPropertyList;

            linearSearchPropertyList = propertyList;
            binarySearchPropertyList = propertyList;

            cin.ignore();

            string tempRegion;
            cout << "Please type the region: " ;
            getline(cin, tempRegion);

            

            bool found = false;

            // For Linear Search

            cout << "*DISPLAY OF 10 RELEVANT PROPERTIES* " << endl << endl;

            DoublyNode<Property> *temp = linearSearchPropertyList.head;
            int count = 0;


            while (temp != nullptr && count < 10) {
                string strRegion = temp->data.getRegion();

                if (strRegion == tempRegion)
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }

                temp = temp->next;

            }

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl << endl;
            }

        }

    }

    static void searchFunction2(DoublyLinkedList<Property> &propertyList){
        
        int searchChoice;

        cout << "\n======== Search Menu ========" << endl;
        cout << "(1) Number of Rooms" << endl;
        cout << "(2) Number of Bathrooms" << endl;
        cout << "(3) Property Type" << endl;
        cout << "(4) Region" << endl;
        cout << "(5) Back" << endl;
        cout << "\nPlease enter your choice (1-5): ";

        cin >> searchChoice;

        if(searchChoice == 1){
            DoublyLinkedList<Property> linearSearchPropertyList;
            DoublyLinkedList<Property> binarySearchPropertyList;

            linearSearchPropertyList = propertyList;
            binarySearchPropertyList = propertyList;

            int tempRooms;
            cout << "Please type the number of rooms: " ;
            cin >> tempRooms;

            int roomRange;
            cout << endl << "Lower than equal to " << tempRooms << " or higher than equal to " << tempRooms << " (Please type 0 for lower than equal to or 1 for higher than equal to) : " ;
            cin >> roomRange;

            bool found = false;

            // For Linear Search

            cout << "IN LINEAR SEARCH: " << endl << endl;

            DoublyNode<Property> *temp = linearSearchPropertyList.head;
            int count = 0;

            auto start1 = high_resolution_clock::now();

            while (temp != nullptr && count < 1) {
                string strRooms = temp->data.getRooms();

                if(roomRange == 0) {
                    if (strRooms <= to_string(tempRooms))
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }
                }

                if(roomRange == 1) {
                    if (strRooms >= to_string(tempRooms))
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }
                }

                temp = temp->next;
            }

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl << endl;
            }

            auto stop1 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(stop1 - start1);

            cout << "Linear Search Execution Time: " << duration1.count() << " microseconds" << endl << endl;


            // For Binary Search

            cout << "IN BINARY SEARCH: " << endl << endl;

            found = false;

            count = 0;

            DoublyNode<Property> *start = binarySearchPropertyList.head;

            // Sort first before binary search

            sortList(&start, searchChoice);

            DoublyNode<Property> *last = NULL;

            auto start2 = high_resolution_clock::now();

            do {
                if (start == NULL)
                    break;

                DoublyNode<Property> *slow = start;
                DoublyNode<Property> *fast = start->next;

                while (fast != last) {
                    fast = fast -> next;
                    if (fast != last){
                        slow = slow -> next;
                        fast = fast -> next;
                    }
                }

                DoublyNode<Property> *mid = slow;

                if (mid == NULL)
                    break;

                if (stoi(mid -> data.getRooms()) == tempRooms){
                    cout << "Property ID: " << temp->data.getID() << endl;
                    cout << "Property Name: " << temp->data.getPropname() << endl;
                    cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                    cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                    cout << "Location: " << temp->data.getLocation() << endl;
                    cout << "Property Type: " << temp->data.getPropertyType() << endl;
                    cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                    cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                    cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                    cout << "Size: " << temp->data.getSizes() << endl;
                    cout << "Furnished: " << temp->data.getFurnished() << endl;
                    cout << "Facilities: " << temp->data.getFacilities() << endl;
                    cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                    cout << "Region: " << temp->data.getRegion() << endl << endl;
                    found = true;
                    break;
                }
                else if (stoi(mid -> data.getRooms()) < tempRooms)
                    start = mid -> next;
                else
                    last = mid;

                        
            }while (last == NULL || last != start);

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl;
            }

            auto stop2 = high_resolution_clock::now();

            auto duration2 = duration_cast<microseconds>(stop2 - start2);

            cout << "Binary Search Execution Time: " << duration2.count() << " microseconds" << endl << endl;

        }

        if(searchChoice == 2){
            DoublyLinkedList<Property> linearSearchPropertyList;
            DoublyLinkedList<Property> binarySearchPropertyList;

            linearSearchPropertyList = propertyList;
            binarySearchPropertyList = propertyList;

            int tempBathrooms;
            cout << "Please type the number of bathrooms: " ;
            cin >> tempBathrooms;

            int bathroomRange;
            cout << endl << "Lower than equal to " << tempBathrooms << " or higher than equal to " << tempBathrooms << " (Please type 0 for lower than equal to or 1 for higher than equal to) : " ;
            cin >> bathroomRange;

            bool found = false;

            // For Linear Search

            cout << "IN LINEAR SEARCH: " << endl << endl;

            DoublyNode<Property> *temp = linearSearchPropertyList.head;
            int count = 0;

            auto start1 = high_resolution_clock::now();

            while (temp != nullptr && count < 1) {
                string strBathrooms = temp->data.getBathrooms();

                if(bathroomRange == 0) {
                    if (strBathrooms <= to_string(tempBathrooms))
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }
                }

                if(bathroomRange == 1) {
                    if (strBathrooms >= to_string(tempBathrooms))
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }
                }

                temp = temp->next;
            }

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl << endl;
            }

            auto stop1 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(stop1 - start1);

            cout << "Linear Search Execution Time: " << duration1.count() << " microseconds" << endl << endl;


            // For Binary Search

            cout << "IN BINARY SEARCH: " << endl << endl;

            found = false;

            count = 0;

            DoublyNode<Property> *start = binarySearchPropertyList.head;

            // Sort first before binary search

            sortList(&start, searchChoice);

            DoublyNode<Property> *last = NULL;

            auto start2 = high_resolution_clock::now();

            do {
                if (start == NULL)
                    break;

                DoublyNode<Property> *slow = start;
                DoublyNode<Property> *fast = start->next;

                while (fast != last) {
                    fast = fast -> next;
                    if (fast != last){
                        slow = slow -> next;
                        fast = fast -> next;
                    }
                }

                DoublyNode<Property> *mid = slow;

                if (mid == NULL)
                    break;

                if (stoi(mid -> data.getBathrooms()) == tempBathrooms){
                    cout << "Property ID: " << temp->data.getID() << endl;
                    cout << "Property Name: " << temp->data.getPropname() << endl;
                    cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                    cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                    cout << "Location: " << temp->data.getLocation() << endl;
                    cout << "Property Type: " << temp->data.getPropertyType() << endl;
                    cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                    cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                    cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                    cout << "Size: " << temp->data.getSizes() << endl;
                    cout << "Furnished: " << temp->data.getFurnished() << endl;
                    cout << "Facilities: " << temp->data.getFacilities() << endl;
                    cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                    cout << "Region: " << temp->data.getRegion() << endl << endl;
                    found = true;
                    break;
                }
                else if (stoi(mid -> data.getBathrooms()) < tempBathrooms)
                    start = mid -> next;
                else
                    last = mid;

                        
            }while (last == NULL || last != start);

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl;
            }

            auto stop2 = high_resolution_clock::now();

            auto duration2 = duration_cast<microseconds>(stop2 - start2);

            cout << "Binary Search Execution Time: " << duration2.count() << " microseconds" << endl << endl;

        }

        if(searchChoice == 3){
            DoublyLinkedList<Property> linearSearchPropertyList;
            DoublyLinkedList<Property> binarySearchPropertyList;

            linearSearchPropertyList = propertyList;
            binarySearchPropertyList = propertyList;

            cin.ignore();

            string tempPropertyType;
            cout << "Please type the property type: " ;
            getline(cin, tempPropertyType);

            

            bool found = false;

            // For Linear Search

            cout << "IN LINEAR SEARCH: " << endl << endl;

            DoublyNode<Property> *temp = linearSearchPropertyList.head;
            int count = 0;

            auto start1 = high_resolution_clock::now();

            while (temp != nullptr && count < 1) {
                string strPropertyType = temp->data.getPropertyType();

                if (strPropertyType == tempPropertyType)
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }

                temp = temp->next;
            }

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl << endl;
            }

            auto stop1 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(stop1 - start1);

            cout << "Linear Search Execution Time: " << duration1.count() << " microseconds" << endl << endl;

            // For Binary Search

            cout << "IN BINARY SEARCH: " << endl << endl;

            found = false;

            count = 0;

            DoublyNode<Property> *start = binarySearchPropertyList.head;

            // Sort first before binary search

            sortList(&start, searchChoice);

            DoublyNode<Property> *last = NULL;

            auto start2 = high_resolution_clock::now();

            do {
                if (start == NULL)
                    break;

                DoublyNode<Property> *slow = start;
                DoublyNode<Property> *fast = start->next;

                while (fast != last) {
                    fast = fast -> next;
                    if (fast != last){
                        slow = slow -> next;
                        fast = fast -> next;
                    }
                }

                DoublyNode<Property> *mid = slow;

                if (mid == NULL)
                    break;

                if (mid -> data.getPropertyType() == tempPropertyType){
                    cout << "Property ID: " << temp->data.getID() << endl;
                    cout << "Property Name: " << temp->data.getPropname() << endl;
                    cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                    cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                    cout << "Location: " << temp->data.getLocation() << endl;
                    cout << "Property Type: " << temp->data.getPropertyType() << endl;
                    cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                    cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                    cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                    cout << "Size: " << temp->data.getSizes() << endl;
                    cout << "Furnished: " << temp->data.getFurnished() << endl;
                    cout << "Facilities: " << temp->data.getFacilities() << endl;
                    cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                    cout << "Region: " << temp->data.getRegion() << endl << endl;
                    found = true;
                    break;
                }
                else if (mid -> data.getPropertyType() < tempPropertyType)
                    start = mid -> next;
                else
                    last = mid;

                        
            }while (last == NULL || last != start);

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl;
            }

            auto stop2 = high_resolution_clock::now();

            auto duration2 = duration_cast<microseconds>(stop2 - start2);

            cout << "Binary Search Execution Time: " << duration2.count() << " microseconds" << endl << endl;

        }

        if(searchChoice == 4){
            DoublyLinkedList<Property> linearSearchPropertyList;
            DoublyLinkedList<Property> binarySearchPropertyList;

            linearSearchPropertyList = propertyList;
            binarySearchPropertyList = propertyList;

            cin.ignore();

            string tempRegion;
            cout << "Please type the region: " ;
            getline(cin, tempRegion);


            bool found = false;

            // For Linear Search

            cout << "IN LINEAR SEARCH: " << endl << endl;

            DoublyNode<Property> *temp = linearSearchPropertyList.head;
            int count = 0;

            auto start1 = high_resolution_clock::now();

            while (temp != nullptr && count < 1) {
                string strRegion = temp->data.getRegion();

                if (strRegion == tempRegion)
                    {
                        cout << "Property ID: " << temp->data.getID() << endl;
                        cout << "Property Name: " << temp->data.getPropname() << endl;
                        cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                        cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                        cout << "Location: " << temp->data.getLocation() << endl;
                        cout << "Property Type: " << temp->data.getPropertyType() << endl;
                        cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                        cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                        cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                        cout << "Size: " << temp->data.getSizes() << endl;
                        cout << "Furnished: " << temp->data.getFurnished() << endl;
                        cout << "Facilities: " << temp->data.getFacilities() << endl;
                        cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                        cout << "Region: " << temp->data.getRegion() << endl << endl;
                        found = true; // Found the target value at index i
                        count++;
                    }

                temp = temp->next;
            }

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl << endl;
            }

            auto stop1 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(stop1 - start1);

            cout << "Linear Search Execution Time: " << duration1.count() << " microseconds" << endl << endl;


            // For Binary Search

            cout << "IN BINARY SEARCH: " << endl << endl;

            found = false;

            count = 0;

            DoublyNode<Property> *start = binarySearchPropertyList.head;

            // Sort first before binary search

            sortList(&start, searchChoice);

            DoublyNode<Property> *last = NULL;

            auto start2 = high_resolution_clock::now();

            do {
                if (start == NULL)
                    break;

                DoublyNode<Property> *slow = start;
                DoublyNode<Property> *fast = start->next;

                while (fast != last) {
                    fast = fast -> next;
                    if (fast != last){
                        slow = slow -> next;
                        fast = fast -> next;
                    }
                }

                DoublyNode<Property> *mid = slow;

                if (mid == NULL)
                    break;

                if (mid -> data.getRegion() == tempRegion){
                    cout << "Property ID: " << temp->data.getID() << endl;
                    cout << "Property Name: " << temp->data.getPropname() << endl;
                    cout << "Completion Year: " << temp->data.getCompletionYear() << endl;
                    cout << "Monthly Rent: " << temp->data.getMonthlyRent() << endl;
                    cout << "Location: " << temp->data.getLocation() << endl;
                    cout << "Property Type: " << temp->data.getPropertyType() << endl;
                    cout << "Number of Rooms: " << temp->data.getRooms() << endl;
                    cout << "Number of Parkings: " << temp->data.getParkings() << endl;
                    cout << "Number of Bathrooms: " << temp->data.getBathrooms() << endl;
                    cout << "Size: " << temp->data.getSizes() << endl;
                    cout << "Furnished: " << temp->data.getFurnished() << endl;
                    cout << "Facilities: " << temp->data.getFacilities() << endl;
                    cout << "Additional Facilities: " << temp->data.getAdditionalFacilities() << endl;
                    cout << "Region: " << temp->data.getRegion() << endl << endl;
                    found = true;
                    break;
                }
                else if (mid -> data.getRegion() < tempRegion)
                    start = mid -> next;
                else
                    last = mid;

                        
            }while (last == NULL || last != start);

            if (!found)
            {
                cout << "No property can be found in the range of completion year that you have specified" << endl;
            }

            auto stop2 = high_resolution_clock::now();

            auto duration2 = duration_cast<microseconds>(stop2 - start2);

            cout << "Binary Search Execution Time: " << duration2.count() << " microseconds" << endl << endl;

        }

    }

    static DoublyNode<Property> *merge_sort(DoublyNode<Property> *head, int searchChoice){
        // base case
        if(head == NULL || head->next == NULL)
        return head;
 
        // recursive case
        // Step 1: divide the linked list into
        // two equal linked lists
        DoublyNode<Property> *mid = mid_point(head);
        DoublyNode<Property> *a = head;
        DoublyNode<Property> *b = mid->next;
 
        mid->next = NULL;
 
        // Step 2: recursively sort the smaller
        // linked lists
        a = merge_sort(a, searchChoice);
        b = merge_sort(b, searchChoice);
 
        // Step 3: merge the sorted linked lists
        DoublyNode<Property> *c = merge(a, b, searchChoice);
 
    return c;
    }

    static DoublyNode<Property> *mid_point(DoublyNode<Property> *head)
    {
        // base case
        if(head == NULL || head->next == NULL)
            return head;
 
        // recursive case
        DoublyNode<Property> *fast = head;
        DoublyNode<Property> *slow = head;
 
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next;
 
            if(fast->next == NULL)
                break;
 
            fast = fast->next;
            slow = slow->next;
        }
 
        return slow;
    }

    static DoublyNode<Property> *merge(DoublyNode<Property> *a, DoublyNode<Property> *b, int searchChoice)
    {
        // base case
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;
 
        // recursive case
        // take a head pointer
        DoublyNode<Property> *c;

        if(searchChoice == 1){
 
            if(a->data.getRooms() < b->data.getRooms())
            {
                c = a;
                c->next = merge(a->next, b, searchChoice);
            }
            else
            {
                c = b;
                c->next = merge(a, b->next, searchChoice);
            }
 
            return c;
        }

        if(searchChoice == 2){
 
            if(a->data.getBathrooms() < b->data.getBathrooms())
            {
                c = a;
                c->next = merge(a->next, b, searchChoice);
            }
            else
            {
                c = b;
                c->next = merge(a, b->next, searchChoice);
            }
 
            return c;
        }

        if(searchChoice == 3){
 
            if(a->data.getPropertyType() < b->data.getPropertyType())
            {
                c = a;
                c->next = merge(a->next, b, searchChoice);
            }
            else
            {
                c = b;
                c->next = merge(a, b->next, searchChoice);
            }
 
            return c;
        }

        if(searchChoice == 4){
 
            if(a->data.getRegion() < b->data.getRegion())
            {
                c = a;
                c->next = merge(a->next, b, searchChoice);
            }
            else
            {
                c = b;
                c->next = merge(a, b->next, searchChoice);
            }
 
            return c;
        }
        
    }

    static void sortList(DoublyNode<Property>** head, int searchChoice)
    {
        // Initialize previous and current 
        // nodes
        DoublyNode<Property>* prev = (*head);
        DoublyNode<Property>* curr = (*head)->next;
  
        // Traverse list
        while (curr != NULL)
        {
            if(searchChoice == 1) {
                // If curr is smaller than prev, 
                // then it must be moved to head
                if (curr->data.getRooms() < prev->data.getRooms())
                {
                    // Detach curr from linked list
                    prev->next = curr->next;
  
                    // Move current node to beginning
                    curr->next = (*head);
                    (*head) = curr;
  
                    // Update current
                    curr = prev;
                }
  
                // Nothing to do if current 
                // element is at right place
                else
                    prev = curr;
  
                // Move current
                curr = curr->next;
            }

            if(searchChoice == 2) {
                // If curr is smaller than prev, 
                // then it must be moved to head
                if (curr->data.getBathrooms() < prev->data.getBathrooms())
                {
                    // Detach curr from linked list
                    prev->next = curr->next;
  
                    // Move current node to beginning
                    curr->next = (*head);
                    (*head) = curr;
  
                    // Update current
                    curr = prev;
                }
  
                // Nothing to do if current 
                // element is at right place
                else
                    prev = curr;
  
                // Move current
                curr = curr->next;
            }

            if(searchChoice == 3) {
                // If curr is smaller than prev, 
                // then it must be moved to head
                if (curr->data.getPropertyType() < prev->data.getPropertyType())
                {
                    // Detach curr from linked list
                    prev->next = curr->next;
  
                    // Move current node to beginning
                    curr->next = (*head);
                    (*head) = curr;
  
                    // Update current
                    curr = prev;
                }
  
                // Nothing to do if current 
                // element is at right place
                else
                    prev = curr;
  
                // Move current
                curr = curr->next;
            }

            if(searchChoice == 4) {
                // If curr is smaller than prev, 
                // then it must be moved to head
                if (curr->data.getRegion() < prev->data.getRegion())
                {
                    // Detach curr from linked list
                    prev->next = curr->next;
  
                    // Move current node to beginning
                    curr->next = (*head);
                    (*head) = curr;
  
                    // Update current
                    curr = prev;
                }
  
                // Nothing to do if current 
                // element is at right place
                else
                    prev = curr;
  
                // Move current
                curr = curr->next;
            }
        }
    }

    static void rentRequestFunction(DoublyLinkedList<Property> &favouriteListTenant, Queue<Property>& rentRequestList) {

        favouriteListTenant.showForward();
        string tempPropertyId;
            string makePayment;

            bool found = false;

            cout << endl << "Please enter property ID for rent request: ";
            cin >> tempPropertyId;

            DoublyNode<Property> *curr = favouriteListTenant.head;

            while (curr != nullptr)
            {
                if (curr->data.getID() == tempPropertyId)
                {
                    found = true;
                    break;
                }
                curr = curr->next;
            }

            if(found == true) 
            {
                cout << endl << "Did you make initial payment for this property which is "<< curr->data.getMonthlyRent() << " (y/n): " ;
                cin >> makePayment;

                if(makePayment == "y"){
                    string saveId = curr->data.getID();
                    string savePropName = curr->data.getPropname();
                    string saveCompletionYear = curr->data.getCompletionYear();
                    string saveMonthlyRent = curr->data.getMonthlyRent();
                    string saveLocation = curr->data.getLocation();
                    string savePropertyType = curr->data.getPropertyType();
                    string saveRooms = curr->data.getRooms();
                    string saveParkings = curr->data.getParkings();
                    string saveBathrooms = curr->data.getBathrooms();
                    string saveSize = curr->data.getSizes();
                    string saveFurnished = curr->data.getFurnished();
                    string saveFacilities = curr->data.getFacilities();
                    string saveAdditionalFacilities = curr->data.getAdditionalFacilities();
                    string saveRegion = curr->data.getRegion();

                    Property saveProperty(saveId, savePropName, saveCompletionYear, saveMonthlyRent, saveLocation, savePropertyType, saveRooms, saveParkings, saveBathrooms, saveSize, saveFurnished, saveFacilities, saveAdditionalFacilities, saveRegion);

                    rentRequestList.enqueue(saveProperty);

                    cout << endl << "Rent request is placed successfully" << endl;

                }

                if(makePayment == "n") {
                    cout << endl << "You need to make initial payment for this property first." ;
                    cout << endl << "Rent request is not placed successfully" << endl;
                }

            }

            if(found == false) {
                cout << endl << "The property requested is not in your favourite list. Please add to favourite before request." << endl;
            }



    }

    static void showRentHistory(Queue<Property>& rentingHistoryList) {
        cout << "** Renting History List **" << endl;
        cout << "==========================" << endl << endl;

        // Display the rent history list
        rentingHistoryList.display();
    }

};
