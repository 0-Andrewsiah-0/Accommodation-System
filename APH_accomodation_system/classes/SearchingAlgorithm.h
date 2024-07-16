#pragma once
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

// A generic doubly linked list node
// template <typename T>
// struct Node {
//   T data;
//   Node* prev;
//   Node* next;
// };

// Function to Linear Search for an element in a doubly linked list
template <typename T>
int linearSearch(DoublyNode<T> *head, int value)
{
  int index = 0;
  DoublyNode<T> *temp = head;
  while (temp != nullptr)
  {
    if (temp->data.getId() == value)
    {
      cout << temp->data << endl;
      return index; // Found the target value at index i
    }
    index++;
    temp = temp->next;
  }
  return -1; // Target value not found
};

template <typename T>
bool linearSearchStatus(DoublyNode<T> *head, bool status)
{
  bool found = false;
  DoublyNode<T> *temp = head;
  while (temp != nullptr)
  {
    if (temp->data.getStatus() == status)
    {
      cout << temp->data << endl;
      found = true; // Found the target value at index i
    }
    temp = temp->next;
  }
  return found; // Target value not found
};

template <typename T>
bool linearSearchGender(DoublyNode<T> *head, string status)
{
  bool found = false;
  DoublyNode<T> *temp = head;
  while (temp != nullptr)
  {
    if (temp->data.getGender() == status)
    {
      cout << temp->data << endl;
      found = true; // Found the target value at index i
    }
    temp = temp->next;
  }
  return found; // Target value not found
};

template <typename T>
bool linearSearchPropertyRoomNumberMoreThan(DoublyNode<T> *head, int room)
{
  bool found = false;
  DoublyNode<T> *temp = head;
  int count = 0;
  while (temp != nullptr && count < 10)
  {
    string strsize = temp->data.getRooms();
    // string strnumber = strsize.substr(0,strsize.length() -7);
    int numRoom = stoi(strsize);
    if (numRoom > room)
    {
      cout << temp->data << endl;
      found = true; // Found the target value at index i
      count++;
    }
    temp = temp->next;
  }
  if (!found)
  {
    cout << "There is no property that have more than " << room << " room." << endl;
  }
  return found; // Target value not found
};

template <typename T>
bool linearSearchPropertyType(DoublyNode<T> *head, string type)
{
  bool found = false;
  DoublyNode<T> *temp = head;
  int count = 0;
  while (temp != nullptr && count < 10)
  {
    // string strsize = temp->data.getRooms();
    // string strnumber = strsize.substr(0,strsize.length() -7);
    // int numRoom = stoi(strsize);
    if (temp->data.getPropertyType() == type)
    {
      cout << temp->data << endl;
      found = true; // Found the target value at index i
      count++;
    }
    temp = temp->next;
  }
  if (!found)
  {
    cout << "There is no " << type << " property." << endl;
  }
  return found; // Target value not found
};

template <typename T>
bool linearSearchPropertyRoomNumber(DoublyNode<T> *head, int room)
{
  bool found = false;
  DoublyNode<T> *temp = head;
  int count = 0;
  while (temp != nullptr && count < 10)
  {
    string strsize = temp->data.getRooms();
    // string strnumber = strsize.substr(0,strsize.length() -7);
    int numRoom = stoi(strsize);
    if (numRoom == room)
    {
      cout << temp->data << endl;
      found = true; // Found the target value at index i
      count++;
    }
    temp = temp->next;
  }
  if (!found)
  {
    cout << "There is no property that have " << room << " room." << endl;
  }
  return found; // Target value not found
};

template <typename T>
bool linearSearchPropertySquareFeetMoreThan(DoublyNode<T> *head, int squareFeet)
{
  bool found = false;
  DoublyNode<T> *temp = head;
  int count = 0;
  while (temp != nullptr && count < 10)
  {
    string strsize = temp->data.getSizes();
    string strnumber = strsize.substr(0, strsize.length() - 7);
    int sqaureFeets = stoi(strnumber);
    if (sqaureFeets > squareFeet)
    {
      cout << temp->data << endl;
      found = true; // Found the target value at index i
      count++;
    }
    temp = temp->next;
  }
  if (!found)
  {
    cout << "There is no property size that is more than " << squareFeet << " square feet." << endl;
  }
  return found; // Target value not found
};

template <typename T>
bool linearSearchPropertySquareFeetLessThan(DoublyNode<T> *head, int squareFeet)
{
  bool found = false;
  DoublyNode<T> *temp = head;
  int count = 0;
  while (temp != nullptr && count < 10)
  {
    string strsize = temp->data.getSizes();
    string strnumber = strsize.substr(0, strsize.length() - 7);
    int sqaureFeets = stoi(strnumber);
    if (sqaureFeets < squareFeet)
    {
      cout << temp->data << endl;
      found = true; // Found the target value at index i
      count++;
    }
    temp = temp->next;
  }
  if (!found)
  {
    cout << "There is no property size that is less than " << squareFeet << " square feet." << endl;
  }
  return found; // Target value not found
};

template <typename T>
bool linearSearchPropertyPriceMoreThan(DoublyNode<T> *head, int monthlyRent)
{
  bool found = false;
  DoublyNode<T> *temp = head;
  int count = 0;
  while (temp != nullptr && count < 10)
  {
    string strprice = temp->data.getMonthlyRent();
    string strnumber = strprice.substr(3, strprice.length() - 3 - 9);
    strnumber.erase(remove(strnumber.begin(), strnumber.end(), ' '), strnumber.end());
    int price = stoi(strnumber);
    if (price > monthlyRent)
    {
      cout << temp->data << endl;
      found = true; // Found the target value at index i
      count++;
    }
    temp = temp->next;
  }
  if (!found)
  {
    cout << "There is no property monthly rent that is more than RM " << monthlyRent << "." << endl;
  }
  return found; // Target value not found
};

template <typename T>
bool linearSearchPropertyPriceLessThan(DoublyNode<T> *head, int monthlyRent)
{
  bool found = false;
  DoublyNode<T> *temp = head;
  int count = 0;
  while (temp != nullptr && count < 10)
  {
    string strprice = temp->data.getMonthlyRent();
    string strnumber = strprice.substr(3, strprice.length() - 3 - 9);
    strnumber.erase(remove(strnumber.begin(), strnumber.end(), ' '), strnumber.end());
    int price = stoi(strnumber);
    if (price < monthlyRent)
    {
      cout << temp->data << endl;
      found = true; // Found the target value at index i
      count++;
    }
    temp = temp->next;
  }
  if (!found)
  {
    cout << "There is no property monthly rent that is less than RM " << monthlyRent << "." << endl;
  }
  return found; // Target value not found
};

template <typename T>
bool binarySearch(DoublyNode<T> *head, bool status)
{
  bool found = false;
  if (head == nullptr)
  {
    return found;
  }
  DoublyNode<T> *mid = head;
  while (mid != nullptr)
  {
    if (mid->data.getStatus() == status)
    {
      cout << mid->data << endl;
      found = true;
    }
    mid = mid->next;
  }
  return found;
};

template <typename T>
T *linearSearchId(DoublyNode<T> *head, int ID)
{
  DoublyNode<T> *temp = head;
  while (temp != nullptr)
  {
    if (temp->data.getId() == ID)
    {
      return &(temp->data); // Return the address for found data
    }
    temp = temp->next;
  }
  return nullptr; // Target value not found
}

template <typename T>
DoublyNode<T> *linearSearchDelete(DoublyNode<T> *head, int value)
{
  DoublyNode<T> *temp = head;
  while (temp != nullptr)
  {
    if (temp->data.getId() == value)
    {
      return temp; // Return the node containing the target value
    }
    temp = temp->next;
  }
  return nullptr; // Target value not found
}
