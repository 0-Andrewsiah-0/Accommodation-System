#ifndef utils_H
#define utils_H
#include <string>
#include <algorithm>
#include "../classes/DoublyLinkedList.h"
using namespace std;

namespace utils{

    std::string toLowerCase(const std::string &input)
    {
        std::string lowercasedString = input;
        std::transform(lowercasedString.begin(), lowercasedString.end(), lowercasedString.begin(), ::tolower);
        return lowercasedString;
    }

    std::string toLowerCase(char input)
    {
        std::string lowercasedString(1, std::tolower(input));
        return lowercasedString;
    }

    std::string toUpperCase(const std::string &input)
    {
        std::string uppercasedString = input;
        std::transform(uppercasedString.begin(), uppercasedString.end(), uppercasedString.begin(), ::toupper);
        return uppercasedString;
    }

    std::string toUpperCase(char input)
    {
        std::string uppercasedString(1, std::toupper(input));
        return uppercasedString;
    }

    string askUserUsername()
    {
        string username;
        cout << "Enter username: ";
        cin >> username;
        return username;
    }

    string askUserPassword()
    {
        string password;
        cout << "Enter password: ";
        cin >> password;
        return password;
    }
    
    template <class T>
    DoublyNode<T>* searchByUsername(DoublyLinkedList<T>& list, string username) {
        DoublyNode<T> *current = list.head;
        while (current != nullptr) {
            if (current->data.username == username) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    };

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
    };

}

#endif