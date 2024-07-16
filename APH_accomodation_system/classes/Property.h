#include <iostream>
#include "../others/utils.h"
// #include "Tenant.h"

using namespace std;

class Property
{
private:
    string tenancyProgress;

public:
    string id;
    string propName;
    string completionYear;
    string monthlyRent;
    string location;
    string propertyType;
    string rooms;
    string parkings;
    string bathrooms;
    string size;
    string furnished;
    string facilities;
    string additionalFacilities;
    string region;

    Property(){}
    Property(string id, string propName, string completionYear,
             string monthlyRent, string location, string propertyType,
             string room, string parkings, string bathrooms, string size,
             string furnished, string facilities, string additionalFacilities, string region)
             : tenancyProgress("---")

    {
        this->id = id;
        this->propName = propName;
        this->completionYear = completionYear;
        this->monthlyRent = monthlyRent;
        this->location = location;
        this->propertyType = propertyType;
        this->rooms = room;
        this->parkings = parkings;
        this->bathrooms = bathrooms;
        this->size = size;
        this->furnished = furnished;
        this->facilities = facilities;
        this->additionalFacilities = additionalFacilities;
        this->region = region;
        
    }

    ~Property(){}

    string getID() { return this->id; }     // property ID
    string getPropname() { return this->propName; }
    string getCompletionYear() { return this->completionYear; }
    string getMonthlyRent() { return this->monthlyRent; }
    string getLocation() { return this->location; }
    string getPropertyType() { return this->propertyType; }
    string getRooms() { return this->rooms; }
    string getParkings() { return this->parkings; }
    string getBathrooms() { return this->bathrooms; }
    string getSizes() { return this->size; }
    string getFurnished() { return this->furnished; }
    string getFacilities() { return this->facilities; }
    string getAdditionalFacilities() { return this->additionalFacilities; }
    string getRegion() { return this->region; }
    string getTenancyProgress() { return tenancyProgress; }

    void setId(string id) { this->id = id; }
    void setPropname(string propname) { this->propName = propname; }
    void setCompletionYear(string completionYear) { this->completionYear = completionYear; }
    void setMonthlyRent(string monthlyRent) { this->monthlyRent = monthlyRent; }
    void setLocation(string location) { this->location = location; }
    void setPropertyType(string propertyType) { this->propertyType = propertyType; }
    void setRooms(string rooms) { this->rooms = rooms; }
    void setParkings(string parking) { this->parkings = parking; }
    void setBathrooms(string bathrooms) { this->bathrooms = bathrooms; }
    void setSizes(string sizes) { this->size = sizes; }
    void setFurnished(string furnished) { this->furnished = furnished; }
    void setFacilities(string facilities) { this->facilities = facilities; }
    void setAdditionalFacilities(string additionalFacilities) { this->additionalFacilities = additionalFacilities; }
    void setRegion(string region) { this->region = region; }
    void setTenancyProgress(string tenancyProgress) { 
        if (tenancyProgress == "a" || tenancyProgress == "A" || tenancyProgress == "approved") {
            this->tenancyProgress = "Approved";
        } else if (tenancyProgress == "r" || tenancyProgress == "R" || tenancyProgress == "rejected") {
            this->tenancyProgress = "Rejected";
        } else if (tenancyProgress == "refund" || tenancyProgress == "REFUND") {
            this->tenancyProgress = "Refund";
        } else if (tenancyProgress == "active" || tenancyProgress == "ACTIVE") {
            this->tenancyProgress = "Active";
        } else {
            this->tenancyProgress = "---";  
        }     //This if else use to set the value back to the rentingHistoryList, don't remove it!
    }   

    friend std::ostream &operator<<(std::ostream &os, const Property &property)
    {
        os << "Property ID: " << property.id << "\n"
           << "Property Name: " << utils::toUpperCase(property.propName) << " \n"
           << "Property Completion Year: " << utils::toUpperCase(property.completionYear) << "\n"
           << "Price: " << utils::toUpperCase(property.monthlyRent) << "\n"
           << "Location: " << utils::toUpperCase(property.location) << "\n"
           << "Property Type: " << utils::toUpperCase(property.propertyType) << "\n"
           << "Number of Room: " << utils::toUpperCase(property.rooms) << "\n"
           << "Number of Parkings: " << utils::toUpperCase(property.parkings) << "\n"
           << "Number of Bathrooms: " << utils::toUpperCase(property.bathrooms) << "\n"
           << "Property Size: " << utils::toUpperCase(property.size) << "\n"
           << "Furnished: " << utils::toUpperCase(property.furnished) << "\n"
           << "Facilities: " << utils::toUpperCase(property.facilities) << "\n"
           << "Additional Facilities: " << utils::toUpperCase(property.additionalFacilities) << "\n"
           << "Region: " << utils::toUpperCase(property.region) << "\n"
           << "Tenancy Progress: " << utils::toUpperCase(property.tenancyProgress) << "\n"
           << "=========================================================" << endl;
        return os;
    }
};