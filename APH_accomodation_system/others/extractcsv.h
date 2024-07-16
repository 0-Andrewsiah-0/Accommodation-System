#ifndef EXTRACTCSV_H
#define EXTRACTCSV_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "../classes/DoublyLinkedList.h"
// #include "../classes/Property.h"


DoublyLinkedList<Property> initializeProperty(){    
    DoublyLinkedList<Property> propertyList;
    const string filepath = "csv/mudah-apartment-kl-selangor.csv";
    ifstream file;
    file.open(filepath);
    string line;
    getline(file, line);
    line = "";
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> data;
        string item;

        while (getline(ss, item, ','))
        {
            if (item.front() == '"' && item.back() != '"')
            {
                // handle quoted dield spanning multiple lines
                string nextitem;
                while (getline(ss, nextitem, ','))
                {
                    item += "," + nextitem;
                    if (nextitem.back() == '"')
                    {
                        break;
                    }
                }
            }
            data.push_back(item);
        }

        string id = data[0];
        string propName = data[1];
        string completionYear = data[2];
        string monthlyRent = data[3];
        string location = data[4];
        string propertyType = data[5];
        string rooms = data[6];
        string parkings = data[7];
        string bathrooms = data[8];
        string size = data[9];
        string furnished = data[10];
        string facilities = data[11];
        string additionalFacilities = data[12];
        string region = data[13];

        Property property(id, propName, completionYear, monthlyRent, location, propertyType,
                          rooms, parkings, bathrooms, size, furnished, facilities, additionalFacilities, region);

        propertyList.insertAtEnd(property);
    }
    return propertyList;
}

#endif