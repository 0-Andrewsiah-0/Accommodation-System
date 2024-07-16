#include <iostream>

using namespace std;


template<typename T>
void swapNodes(DoublyNode<T>* a, DoublyNode<T>* b) {

    if(a == nullptr||b == nullptr){
        return;
    } //if either node that is passed in points to null, cancel swap


    T temp = a->data; //swap data positions
    a->data = b->data;
    b->data = temp;

   
}

template<typename T>
void bubbleSort(DoublyLinkedList<T>& propertyList, const string& sortBy, bool ascending = true) {

    if (propertyList.isEmpty() || (sortBy != "monthlyRent" && sortBy != "size" && sortBy != "location")) {
        std::cout<<"Sorting not performed!"<<std::endl;
        return; // If the list is empty or sortBy is invalid, return without sorting.
    }

    int size = propertyList.getSize();
    DoublyNode<T>* current;
    DoublyNode<T>* nextNode;
    bool swapped;


    for (int i = 0; i < size - 1; ++i) {
        current = propertyList.getHead();
        swapped = false;


        for (int j = 0; j < size - i - 1; ++j) {
            nextNode = current->next;

            bool shouldSwap = false;

            int currentVal, nextVal;

            if (sortBy == "monthlyRent") {
            
                try {
                    string rawRent = current->data.getMonthlyRent();
                    if (rawRent.size() >= 12) // checking if the size of recieved string is not out of range
                    { 
                    string strRent1 = rawRent.substr(3, rawRent.length() - 3 - 9);
                    strRent1.erase(remove(strRent1.begin(), strRent1.end(), ' '), strRent1.end());
                    currentVal = stoi(strRent1); //trim and converting to int
                    } else {
                        currentVal = 0;
                    }

                    string rawNextRent = nextNode->data.getMonthlyRent();
                    if (rawNextRent.size() >= 12) // checking if the size of recieved string is not out of range
                    { 
                    string strRent2 = rawNextRent.substr(3, rawNextRent.length() - 3 - 9);
                    strRent2.erase(remove(strRent2.begin(), strRent2.end(), ' '), strRent2.end());
                    nextVal = stoi(strRent2); //trim and converting to int
                    } else {
                        nextVal = 0;
                    }

                } catch (const std::invalid_argument&) {
                    // Unable to convert to int, use lexicographic order for sorting
                    currentVal = 0;
                    nextVal = 0;
                }
            }
                
            if (sortBy == "size") {
                try {
                    string rawSize = current->data.getSizes();
                    string strSize1 = rawSize.substr(0, rawSize.length() - 7);
                    currentVal = stoi(strSize1); 

                    string rawNextSize = nextNode->data.getSizes();
                    string strSize2 = rawNextSize.substr(0, rawNextSize.length() - 7);
                    nextVal = stoi(strSize2);
                    
                } catch (const std::invalid_argument&) {
                    // Unable to convert to int, use lexicographic order for sorting
                    currentVal = 0;
                    nextVal = 0;
                }
            }
            
            if (ascending && sortBy == "location") {
                shouldSwap = (current->data.getLocation() > nextNode->data.getLocation());
                // cout << "yes";
            }
            if (!ascending && sortBy == "location") {
                shouldSwap = (current->data.getLocation() < nextNode->data.getLocation());
            }

            if (ascending && (sortBy == "size" || sortBy == "monthlyRent")){ 
                shouldSwap=currentVal > nextVal; 
            } 
            if (!ascending && (sortBy == "size" || sortBy == "monthlyRent")) {
                shouldSwap=currentVal < nextVal; //compare first and second value, if asc/desc condition is met, shouldswap changes to true
            }

            if(shouldSwap)
            {
                swapNodes(current, nextNode);
                swapped = true; //if shouldswap is true, perform swapping
                // cout << "die la ";
            }


            current = current->next;
        }


        // If no two elements were swapped in the inner loop, the list is already sorted.
        if (!swapped) {
            return;
        }
    }
}

template <typename T>
int partition(DoublyLinkedList<T> &propertyList, const string &sortBy, int low, int high, bool ascending) {

    T pivot = propertyList.getAt(high)->data; // Choose the last element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j <= high - 1; j++)
    {
        bool shouldSwap = false;
        int currentVal, nextVal;

        if (sortBy == "monthlyRent") {
        
            try {
                string rawRent = propertyList.getAt(j)->data.getMonthlyRent();
                if (rawRent.size() >= 12) // checking if the size of recieved string is not out of range
                { 
                string strRent1 = rawRent.substr(3, rawRent.length() - 3 - 9);
                strRent1.erase(remove(strRent1.begin(), strRent1.end(), ' '), strRent1.end());
                currentVal = stoi(strRent1); //trim and converting to int
                } else {
                    currentVal = 0; // assign value as 0
                }

                string rawNextRent = pivot.getMonthlyRent();
                if (rawNextRent.size() >= 12) // checking if the size of recieved string is not out of range
                { 
                string strRent2 = rawNextRent.substr(3, rawNextRent.length() - 3 - 9);
                strRent2.erase(remove(strRent2.begin(), strRent2.end(), ' '), strRent2.end());
                nextVal = stoi(strRent2); //trim and converting to int
                } else {
                    nextVal = 0; // assign value as 0
                }

            } catch (const std::invalid_argument&) {
                // Unable to convert to int, use lexicographic order for sorting
                currentVal = 0;
                nextVal = 0;
            }
        }
            
        if (sortBy == "size") {
            try {
                string rawSize = propertyList.getAt(j)->data.getSizes();
                string strSize1 = rawSize.substr(0, rawSize.length() - 7);
                currentVal = stoi(strSize1); 

                string rawNextSize = pivot.getSizes();
                string strSize2 = rawNextSize.substr(0, rawNextSize.length() - 7);
                nextVal = stoi(strSize2);
                
            } catch (const std::invalid_argument&) {
                // Unable to convert to int, use lexicographic order for sorting
                currentVal = 0;
                nextVal = 0;
            }
        }
        
        if (ascending && sortBy == "location") {
            shouldSwap = (propertyList.getAt(j)->data.getLocation() < pivot.getLocation());
        }
        if (!ascending && sortBy == "location") {
            shouldSwap = (propertyList.getAt(j)->data.getLocation() > pivot.getLocation());
        }

        if (ascending && (sortBy == "size" || sortBy == "monthlyRent")){ 
            shouldSwap=currentVal < nextVal; 
        } 
        if (!ascending && (sortBy == "size" || sortBy == "monthlyRent")) {
            shouldSwap=currentVal > nextVal; //compare first and second value, if asc/desc condition is met, shouldswap changes to true
        }

        if (shouldSwap)
        {
            i++;
            swapNodes(propertyList.getAt(i), propertyList.getAt(j)); // if shouldswap is true, perform swapping
        }
    }

    swapNodes(propertyList.getAt(i + 1), propertyList.getAt(high));
    return (i + 1);
}

template <typename T>
void quickSort(DoublyLinkedList<T> &propertyList, const string &sortBy, int low, int high, bool ascending = true)
{
    if (low < high)
    {
        int pi = partition(propertyList, sortBy, low, high, ascending);

        quickSort(propertyList, sortBy, low, pi - 1, ascending);
        quickSort(propertyList, sortBy, pi + 1, high, ascending);
    }
}

template <typename T>
void quickSorts(DoublyLinkedList<T> &propertyList, const string &sortBy, bool ascending = true)
{
    if (propertyList.isEmpty() || (sortBy != "monthlyRent" && sortBy != "location" && sortBy != "size"))
    {
        cout << "Sorting not performed!" << endl;
        return; // If the list is empty or sortBy is invalid, return without sorting.
    }

    int size = propertyList.getSize();
    quickSort(propertyList, sortBy, 0, size - 1, ascending);
}

;