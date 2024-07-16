#pragma once
#include <iostream>
using namespace std;

/**
 * with class implementation...
 */

template <class T> // abstract type
class DoublyNode
{
public:
    T data;
    DoublyNode<T> *prev;
    DoublyNode<T> *next;
};

template <class T>
class DoublyLinkedList
{
public:
    DoublyNode<T> *head;
    DoublyNode<T> *tail;
    int size;

    DoublyLinkedList()
    {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    DoublyNode<T> *getHead()
    {
        return head;
    }

    void insertAtbeginning(T elem)
    {
        /* PLACE YOUR CODE HERE */
        DoublyNode<T> *newNode = new DoublyNode<T>;
        newNode->data = elem;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head == nullptr)
        {
            /* code */
            head = tail = newNode;
        }
        else
        {
            newNode->next->prev = newNode;
            head = newNode;
        }

        size++;
    }

    void insertAtEnd(T elem)
    {
        DoublyNode<T> *newNode = new DoublyNode<T>;
        newNode->data = elem;
        newNode->next = nullptr;
        newNode->prev = tail;
        tail = newNode;

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev->next = newNode;
        }
        size++;
    }

    void insertItemAt(T elem, int index)
    {
        if (index <= size)
        {
            if (index == 0)
            {
                insertAtbeginning(elem);
            }
            else if (index == size)
            {
                insertAtEnd(elem);
            }
            else
            {
                DoublyNode<T> *newNode = new DoublyNode<T>;
                newNode->data = elem;
                DoublyNode<T> *beforeThis = head;
                for (int i = 0; i < index; i++)
                {
                    /* code */
                    beforeThis = beforeThis->next;
                    newNode->next = beforeThis;
                    newNode->prev = beforeThis->prev;
                    beforeThis->prev = newNode;
                    newNode->prev->next = newNode;
                    size++;
                }
            }
        }
    }

    int getSize()
    {
        return size;
    }

    void showForward(int numberToShow = -1)
    {
        DoublyNode<T> *curr = head;
        int count = 0;
        while (curr != nullptr && (numberToShow == -1 || count < numberToShow))
        {
            cout << count + 1 << endl;
            cout << curr->data << " " << endl;
            curr = curr->next;
            count++;
        }
    }

    void showBackward()
    {
        DoublyNode<T> *curr = tail;
        int count = 0;
        cout << "\n--- DISPLAY LINKED LIST [BACKWARD] = " << size << " elements ---" << endl;
        while (curr != nullptr)
        {
            cout << count + 1 << endl;
            cout << curr->data << " " << endl;
            curr = curr->prev;
            count++;
        }
    }

    void sort()
    {
        /* PLACE YOUR CODE HERE */
    }

    bool find(string username, string password)
    {
        DoublyNode<T> *curr = head;
        while (curr != nullptr)
        {
            if (curr->data.getUsername() == username && curr->data.getPassword() == password && curr->data.getStatus() == true)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    bool findAndUpdateStatus(string id, bool status)
    {
        int finalId = stoi(id.substr(2));
        DoublyNode<T> *curr = head;
        while (curr != nullptr)
        {
            if (curr->data.getId() == finalId)
            {
                curr->data.setStatus(status);
                return true;
            }
            curr = curr->next;
        }
    }

    int findLargestId()
    {
        int largestId = head->data.getId();
        DoublyNode<T> *curr = head->next;

        while (curr != nullptr)
        {
            int currId = curr->data.getId();
            if (currId > largestId)
            {
                largestId = currId;
            }
            curr = curr->next;
        }
        return largestId;
    }

    template <class U>
    void deleteNode(DoublyNode<U>* node)   //use to delete the tenant
    {
        if (node == nullptr) {
            return;
        }
        if (node == head) {
            head = node->next;
        }
        if (node == tail) {
            tail = node->prev;
        }
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        delete node;
        size--;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    DoublyNode<T>* getAt(int index) //return node at desired index value
    {
        if (index < 0 || index >= size) {
            return nullptr; // Index out of bounds
        }

        DoublyNode<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current;
    }

};