#include <iostream>
#include "classes/DoublyLinkedList.h"
#include "classes/Tenant.h"
#include "classes/Manager.h"
#include "classes/Admin.h"
#include "classes/Property.h"
#include "Views/mainMenu.h"
#include <fstream>
#include <vector>
#include <sstream>
#include "classes/SearchingAlgorithm.h"
#include "others/utils.h"
#include "others/extractcsv.h"

using namespace std;

DoublyLinkedList<Admin> initializeAdmin()
{
    DoublyLinkedList<Admin> adminList;
    Admin admin(1, "admin", "admin123", "male");
    adminList.insertAtEnd(admin);
    return adminList;
}

DoublyLinkedList<Manager> initializeManager()
{
    DoublyLinkedList<Manager> managerList;

    Manager manager(1, "manager", "manager123", "male", true);
    Manager manager2(2, "manager2", "manager1234", "female", false);
    Manager manager3(3, "manager3", "manager12345", "male", true);
    Manager manager4(4, "m", "m123", "male", true);

    managerList.insertAtEnd(manager);
    managerList.insertAtEnd(manager2);
    managerList.insertAtEnd(manager3);
    managerList.insertAtEnd(manager4);
    return managerList;
}

DoublyLinkedList<Tenant> initializeTenant()
{
    DoublyLinkedList<Tenant> tenantList;
    Tenant tenant(1, "tenant", "tenant123", "male", false);
    Tenant tenant2(2, "tenant1", "tenant1234", "male", true);
    Tenant tenant3(3, "tenant2", "tenant12345", "male", true);

    tenantList.insertAtEnd(tenant);
    tenantList.insertAtEnd(tenant2);
    tenantList.insertAtEnd(tenant3);
    return tenantList;
}

DoublyLinkedList<Property> initializeFavouriteListAll()
{
    DoublyLinkedList<Property> favouriteListAll;

    // Dummy data for favorite properties
    Property property1("100323185","The Hipster @ Taman Desa","2022","RM 4 200 per month","Kuala Lumpur - Taman Desa","Condominium","5","2","6","1842 sq.ft.","Fully Furnished","Minimart, Gymnasium, Security, Playground, Swimming Pool, Parking, Lift, Barbeque area, Multipurpose hall, Jogging Track","Air-Cond, Cooking Allowed, Washing Machine","Kuala Lumpur");
    Property property2("100323185","The Hipster @ Taman Desa","2022","RM 4 200 per month","Kuala Lumpur - Taman Desa","Condominium","5","2","6","1842 sq.ft.","Fully Furnished","Minimart, Gymnasium, Security, Playground, Swimming Pool, Parking, Lift, Barbeque area, Multipurpose hall, Jogging Track","Air-Cond, Cooking Allowed, Washing Machine","Kuala Lumpur");
    Property property3("100322813","The Park Sky Residence @ Bukit Jalil City","2019","RM 2 500 per month","Kuala Lumpur - Bukit Jalil","Service Residence","2","empty","2","868 sq.ft.","Partially Furnished","Parking, Playground, Swimming Pool, Security, Multipurpose hall, Gymnasium, Jogging Track","Cooking Allowed, Near KTM/LRT", "Kuala Lumpur");
    Property property4("100322813","The Park Sky Residence @ Bukit Jalil City","2019","RM 2 500 per month","Kuala Lumpur - Bukit Jalil","Service Residence","2","empty","2","868 sq.ft.","Partially Furnished","Parking, Playground, Swimming Pool, Security, Multipurpose hall, Gymnasium, Jogging Track","Cooking Allowed, Near KTM/LRT", "Kuala Lumpur");
    Property property5("100322212","Majestic Maxim","2021","RM 1 400 per month","Kuala Lumpur - Cheras","Service Residence","2","2","empty","2,650 sq.ft.","Not Furnished","Parking, Gymnasium, Jogging Track, Lift, Barbeque area, Security, Swimming Pool, Playground","Air-Cond, Near KTM/LRT, Cooking Allowed","Kuala Lumpur");
    Property property6("100310024","Majestic Maxim","2021","RM 1 099 per month","Kuala Lumpur - Cheras","Service Residence","2","1","2","650 sq.ft.","Partially Furnished","Security, Swimming Pool, Parking, Jogging Track, Barbeque area, Playground, Gymnasium, Lift","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property7("100310024","Majestic Maxim","2021","RM 1 099 per month","Kuala Lumpur - Cheras","Service Residence","2","1","2","650 sq.ft.","Partially Furnished","Security, Swimming Pool, Parking, Jogging Track, Barbeque area, Playground, Gymnasium, Lift","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property8("100318578","Kepong Sentral Condominium","2007","RM 999 per month","Kuala Lumpur - Kepong","Condominium","3","1","empty","2,962 sq.ft.","Not Furnished","Security, Minimart, Playground, Squash Court, Jogging Track, Lift, Parking, Swimming Pool, Tennis Court, Gymnasium","empty","Kuala Lumpur");
    Property property9("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property10("100318501","The Hipster @ Taman Desa","2022","RM 2 100 per month","Kuala Lumpur - Taman Desa","Condominium","3","2","empty","2,925 sq.ft.","Fully Furnished","Security, Minimart, Swimming Pool, Squash Court, Lift, Parking, Playground, Gymnasium, Barbeque area, Sauna, Multipurpose hall","Cooking Allowed, Air-Cond, Near KTM/LRT, Washing Machine, Internet","Kuala Lumpur");
    Property property11("100318448","Mont Kiara Astana","1998","RM 4 500 per month","Kuala Lumpur - Mont Kiara","Condominium","4","empty","3","1690 sq.ft.","Fully Furnished","Playground, Barbeque area, Parking, Security, Swimming Pool, Tennis Court, Lift, Gymnasium, Sauna, Multipurpose hall","Air-Cond, Cooking Allowed, Washing Machine, Internet","Kuala Lumpur");
    Property property12("100250824","Sentrio Suites","2017","RM 1 550 per month","Kuala Lumpur - Desa Pandan","Service Residence","1","1","empty","1,570 sq.ft.","Fully Furnished","Parking, Security, Lift, Swimming Pool, Playground, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine","Kuala Lumpur");
    Property property13("100318198","Majestic Maxim","2021","RM 2 300 per month","Kuala Lumpur - Cheras","Service Residence","3","empty","empty","2,1050 sq.ft.","Fully Furnished","Swimming Pool, Gymnasium, Barbeque area, Security, Playground, Lift, Jogging Track, Parking","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property14("100318196","Tiara Mutiara 2","2017","RM 1 500 per month","Kuala Lumpur - Old Klang Road","Service Residence","3","empty","empty","2,900 sq.ft.","Partially Furnished","Sauna, Multipurpose hall, Playground, Swimming Pool, Gymnasium, Security","Air-Cond, Cooking Allowed, Near KTM/LRT","Kuala Lumpur");
    Property property15("100258228","PV9 Residences @ Taman Melati","2022","RM 2 499 per month","Kuala Lumpur - Setapak","Service Residence","4","3","2","1100 sq.ft.","Partially Furnished","Security, Parking, Lift, Swimming Pool, Playground, Minimart, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine, Near KTM/LRT","Kuala Lumpur");
    Property property16("99906090","Bukit Pandan 2","empty","RM 1 450 per month","Kuala Lumpur - Cheras","Condominium","3","1","2","1150 sq.ft.","Fully Furnished","Parking, Security, Lift, Swimming Pool, Playground, Gymnasium, Barbeque area, Minimart, Multipurpose hall, Squash Court, Tennis Court, Jogging Track","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property17("100198517","Angkasa Impian 1","2004","RM 4 000 per month","Kuala Lumpur - Bukit Bintang","Condominium","4","empty","4","2200 sq.ft.","Fully Furnished","Sauna, Playground, Gymnasium, Swimming Pool, Parking, Squash Court, Security, Barbeque area","Air-Cond, Cooking Allowed, Washing Machine, Internet","Kuala Lumpur");
    Property property18("100318501","The Hipster @ Taman Desa","2022","RM 2 100 per month","Kuala Lumpur - Taman Desa","Condominium","3","2","empty","2,925 sq.ft.","Fully Furnished","Security, Minimart, Swimming Pool, Squash Court, Lift, Parking, Playground, Gymnasium, Barbeque area, Sauna, Multipurpose hall","Cooking Allowed, Air-Cond, Near KTM/LRT, Washing Machine, Internet","Kuala Lumpur");
    Property property19("100318448","Mont Kiara Astana","1998","RM 4 500 per month","Kuala Lumpur - Mont Kiara","Condominium","4","empty","3","1690 sq.ft.","Fully Furnished","Playground, Barbeque area, Parking, Security, Swimming Pool, Tennis Court, Lift, Gymnasium, Sauna, Multipurpose hall","Air-Cond, Cooking Allowed, Washing Machine, Internet","Kuala Lumpur");
    Property property20("100250824","Sentrio Suites","2017","RM 1 550 per month","Kuala Lumpur - Desa Pandan","Service Residence","1","1","empty","1,570 sq.ft.","Fully Furnished","Parking, Security, Lift, Swimming Pool, Playground, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine","Kuala Lumpur");
    Property property21("100318198","Majestic Maxim","2021","RM 2 300 per month","Kuala Lumpur - Cheras","Service Residence","3","empty","empty","2,1050 sq.ft.","Fully Furnished","Swimming Pool, Gymnasium, Barbeque area, Security, Playground, Lift, Jogging Track, Parking","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property22("100318196","Tiara Mutiara 2","2017","RM 1 500 per month","Kuala Lumpur - Old Klang Road","Service Residence","3","empty","empty","2,900 sq.ft.","Partially Furnished","Sauna, Multipurpose hall, Playground, Swimming Pool, Gymnasium, Security","Air-Cond, Cooking Allowed, Near KTM/LRT","Kuala Lumpur");
    Property property23("100258228","PV9 Residences @ Taman Melati","2022","RM 2 499 per month","Kuala Lumpur - Setapak","Service Residence","4","3","2","1100 sq.ft.","Partially Furnished","Security, Parking, Lift, Swimming Pool, Playground, Minimart, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine, Near KTM/LRT","Kuala Lumpur");
    Property property24("99906090","Bukit Pandan 2","empty","RM 1 450 per month","Kuala Lumpur - Cheras","Condominium","3","1","2","1150 sq.ft.","Fully Furnished","Parking, Security, Lift, Swimming Pool, Playground, Gymnasium, Barbeque area, Minimart, Multipurpose hall, Squash Court, Tennis Court, Jogging Track","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property25("100198517","Angkasa Impian 1","2004","RM 4 000 per month","Kuala Lumpur - Bukit Bintang","Condominium","4","empty","4","2200 sq.ft.","Fully Furnished","Sauna, Playground, Gymnasium, Swimming Pool, Parking, Squash Court, Security, Barbeque area","Air-Cond, Cooking Allowed, Washing Machine, Internet","Kuala Lumpur");
    Property property26("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property27("100318501","The Hipster @ Taman Desa","2022","RM 2 100 per month","Kuala Lumpur - Taman Desa","Condominium","3","2","empty","2,925 sq.ft.","Fully Furnished","Security, Minimart, Swimming Pool, Squash Court, Lift, Parking, Playground, Gymnasium, Barbeque area, Sauna, Multipurpose hall","Cooking Allowed, Air-Cond, Near KTM/LRT, Washing Machine, Internet","Kuala Lumpur");
    Property property28("100318448","Mont Kiara Astana","1998","RM 4 500 per month","Kuala Lumpur - Mont Kiara","Condominium","4","empty","3","1690 sq.ft.","Fully Furnished","Playground, Barbeque area, Parking, Security, Swimming Pool, Tennis Court, Lift, Gymnasium, Sauna, Multipurpose hall","Air-Cond, Cooking Allowed, Washing Machine, Internet","Kuala Lumpur");
    Property property29("100322813","The Park Sky Residence @ Bukit Jalil City","2019","RM 2 500 per month","Kuala Lumpur - Bukit Jalil","Service Residence","2","empty","2","868 sq.ft.","Partially Furnished","Parking, Playground, Swimming Pool, Security, Multipurpose hall, Gymnasium, Jogging Track","Cooking Allowed, Near KTM/LRT", "Kuala Lumpur");
    Property property30("100322212","Majestic Maxim","2021","RM 1 400 per month","Kuala Lumpur - Cheras","Service Residence","2","2","empty","2,650 sq.ft.","Not Furnished","Parking, Gymnasium, Jogging Track, Lift, Barbeque area, Security, Swimming Pool, Playground","Air-Cond, Near KTM/LRT, Cooking Allowed","Kuala Lumpur");
    Property property31("100310024","Majestic Maxim","2021","RM 1 099 per month","Kuala Lumpur - Cheras","Service Residence","2","1","2","650 sq.ft.","Partially Furnished","Security, Swimming Pool, Parking, Jogging Track, Barbeque area, Playground, Gymnasium, Lift","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property32("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property33("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property34("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property35("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property36("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property37("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property38("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property39("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property40("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property41("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property42("100318196","Tiara Mutiara 2","2017","RM 1 500 per month","Kuala Lumpur - Old Klang Road","Service Residence","3","empty","empty","2,900 sq.ft.","Partially Furnished","Sauna, Multipurpose hall, Playground, Swimming Pool, Gymnasium, Security","Air-Cond, Cooking Allowed, Near KTM/LRT","Kuala Lumpur");
    Property property43("100318196","Tiara Mutiara 2","2017","RM 1 500 per month","Kuala Lumpur - Old Klang Road","Service Residence","3","empty","empty","2,900 sq.ft.","Partially Furnished","Sauna, Multipurpose hall, Playground, Swimming Pool, Gymnasium, Security","Air-Cond, Cooking Allowed, Near KTM/LRT","Kuala Lumpur");
    Property property44("100318196","Tiara Mutiara 2","2017","RM 1 500 per month","Kuala Lumpur - Old Klang Road","Service Residence","3","empty","empty","2,900 sq.ft.","Partially Furnished","Sauna, Multipurpose hall, Playground, Swimming Pool, Gymnasium, Security","Air-Cond, Cooking Allowed, Near KTM/LRT","Kuala Lumpur");
    Property property45("100318196","Tiara Mutiara 2","2017","RM 1 500 per month","Kuala Lumpur - Old Klang Road","Service Residence","3","empty","empty","2,900 sq.ft.","Partially Furnished","Sauna, Multipurpose hall, Playground, Swimming Pool, Gymnasium, Security","Air-Cond, Cooking Allowed, Near KTM/LRT","Kuala Lumpur");
    Property property46("100318196","Tiara Mutiara 2","2017","RM 1 500 per month","Kuala Lumpur - Old Klang Road","Service Residence","3","empty","empty","2,900 sq.ft.","Partially Furnished","Sauna, Multipurpose hall, Playground, Swimming Pool, Gymnasium, Security","Air-Cond, Cooking Allowed, Near KTM/LRT","Kuala Lumpur");
    Property property47("100318196","Tiara Mutiara 2","2017","RM 1 500 per month","Kuala Lumpur - Old Klang Road","Service Residence","3","empty","empty","2,900 sq.ft.","Partially Furnished","Sauna, Multipurpose hall, Playground, Swimming Pool, Gymnasium, Security","Air-Cond, Cooking Allowed, Near KTM/LRT","Kuala Lumpur");
    Property property48("100318196","Tiara Mutiara 2","2017","RM 1 500 per month","Kuala Lumpur - Old Klang Road","Service Residence","3","empty","empty","2,900 sq.ft.","Partially Furnished","Sauna, Multipurpose hall, Playground, Swimming Pool, Gymnasium, Security","Air-Cond, Cooking Allowed, Near KTM/LRT","Kuala Lumpur");
    Property property49("100318196","Tiara Mutiara 2","2017","RM 1 500 per month","Kuala Lumpur - Old Klang Road","Service Residence","3","empty","empty","2,900 sq.ft.","Partially Furnished","Sauna, Multipurpose hall, Playground, Swimming Pool, Gymnasium, Security","Air-Cond, Cooking Allowed, Near KTM/LRT","Kuala Lumpur");
    Property property50("100258228","PV9 Residences @ Taman Melati","2022","RM 2 499 per month","Kuala Lumpur - Setapak","Service Residence","4","3","2","1100 sq.ft.","Partially Furnished","Security, Parking, Lift, Swimming Pool, Playground, Minimart, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine, Near KTM/LRT","Kuala Lumpur");
    Property property51("100258228","PV9 Residences @ Taman Melati","2022","RM 2 499 per month","Kuala Lumpur - Setapak","Service Residence","4","3","2","1100 sq.ft.","Partially Furnished","Security, Parking, Lift, Swimming Pool, Playground, Minimart, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine, Near KTM/LRT","Kuala Lumpur");
    Property property52("100258228","PV9 Residences @ Taman Melati","2022","RM 2 499 per month","Kuala Lumpur - Setapak","Service Residence","4","3","2","1100 sq.ft.","Partially Furnished","Security, Parking, Lift, Swimming Pool, Playground, Minimart, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine, Near KTM/LRT","Kuala Lumpur");
    Property property53("100258228","PV9 Residences @ Taman Melati","2022","RM 2 499 per month","Kuala Lumpur - Setapak","Service Residence","4","3","2","1100 sq.ft.","Partially Furnished","Security, Parking, Lift, Swimming Pool, Playground, Minimart, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine, Near KTM/LRT","Kuala Lumpur");
    Property property54("100258228","PV9 Residences @ Taman Melati","2022","RM 2 499 per month","Kuala Lumpur - Setapak","Service Residence","4","3","2","1100 sq.ft.","Partially Furnished","Security, Parking, Lift, Swimming Pool, Playground, Minimart, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine, Near KTM/LRT","Kuala Lumpur");
    Property property55("100258228","PV9 Residences @ Taman Melati","2022","RM 2 499 per month","Kuala Lumpur - Setapak","Service Residence","4","3","2","1100 sq.ft.","Partially Furnished","Security, Parking, Lift, Swimming Pool, Playground, Minimart, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine, Near KTM/LRT","Kuala Lumpur");
    
    
    favouriteListAll.insertAtEnd(property1);
    favouriteListAll.insertAtEnd(property2);
    favouriteListAll.insertAtEnd(property3);
    favouriteListAll.insertAtEnd(property4);
    favouriteListAll.insertAtEnd(property5);
    favouriteListAll.insertAtEnd(property6);
    favouriteListAll.insertAtEnd(property7);
    favouriteListAll.insertAtEnd(property8);
    favouriteListAll.insertAtEnd(property9);
    favouriteListAll.insertAtEnd(property10);
    favouriteListAll.insertAtEnd(property11);
    favouriteListAll.insertAtEnd(property12);
    favouriteListAll.insertAtEnd(property13);
    favouriteListAll.insertAtEnd(property14);
    favouriteListAll.insertAtEnd(property15);
    favouriteListAll.insertAtEnd(property16);
    favouriteListAll.insertAtEnd(property17);
    favouriteListAll.insertAtEnd(property18);
    favouriteListAll.insertAtEnd(property19);
    favouriteListAll.insertAtEnd(property20);
    favouriteListAll.insertAtEnd(property21);
    favouriteListAll.insertAtEnd(property22);
    favouriteListAll.insertAtEnd(property23);
    favouriteListAll.insertAtEnd(property24);
    favouriteListAll.insertAtEnd(property25);
    favouriteListAll.insertAtEnd(property26);
    favouriteListAll.insertAtEnd(property27);
    favouriteListAll.insertAtEnd(property28);
    favouriteListAll.insertAtEnd(property29);
    favouriteListAll.insertAtEnd(property30);
    favouriteListAll.insertAtEnd(property31);
    favouriteListAll.insertAtEnd(property32);
    favouriteListAll.insertAtEnd(property33);
    favouriteListAll.insertAtEnd(property34);
    favouriteListAll.insertAtEnd(property35);
    favouriteListAll.insertAtEnd(property36);
    favouriteListAll.insertAtEnd(property37);
    favouriteListAll.insertAtEnd(property38);
    favouriteListAll.insertAtEnd(property39);
    favouriteListAll.insertAtEnd(property40);
    favouriteListAll.insertAtEnd(property41);
    favouriteListAll.insertAtEnd(property42);
    favouriteListAll.insertAtEnd(property43);
    favouriteListAll.insertAtEnd(property44);
    favouriteListAll.insertAtEnd(property45);
    favouriteListAll.insertAtEnd(property46);
    favouriteListAll.insertAtEnd(property47);
    favouriteListAll.insertAtEnd(property48);
    favouriteListAll.insertAtEnd(property49);
    favouriteListAll.insertAtEnd(property50);
    favouriteListAll.insertAtEnd(property51);
    favouriteListAll.insertAtEnd(property52);
    favouriteListAll.insertAtEnd(property53);
    favouriteListAll.insertAtEnd(property54);
    favouriteListAll.insertAtEnd(property55);



    return favouriteListAll;
}

DoublyLinkedList<Property> initializeFavouriteListTenant()
{
    DoublyLinkedList<Property> favouriteListTenant;

    Property property1("100323185","The Hipster @ Taman Desa","2022","RM 4 200 per month","Kuala Lumpur - Taman Desa","Condominium","5","2","6","1842 sq.ft.","Fully Furnished","Minimart, Gymnasium, Security, Playground, Swimming Pool, Parking, Lift, Barbeque area, Multipurpose hall, Jogging Track","Air-Cond, Cooking Allowed, Washing Machine","Kuala Lumpur");
    Property property2("100323185","The Hipster @ Taman Desa","2022","RM 4 200 per month","Kuala Lumpur - Taman Desa","Condominium","5","2","6","1842 sq.ft.","Fully Furnished","Minimart, Gymnasium, Security, Playground, Swimming Pool, Parking, Lift, Barbeque area, Multipurpose hall, Jogging Track","Air-Cond, Cooking Allowed, Washing Machine","Kuala Lumpur");
    Property property3("100322813","The Park Sky Residence @ Bukit Jalil City","2019","RM 2 500 per month","Kuala Lumpur - Bukit Jalil","Service Residence","2","empty","2","868 sq.ft.","Partially Furnished","Parking, Playground, Swimming Pool, Security, Multipurpose hall, Gymnasium, Jogging Track","Cooking Allowed, Near KTM/LRT", "Kuala Lumpur");
    Property property4("100322813","The Park Sky Residence @ Bukit Jalil City","2019","RM 2 500 per month","Kuala Lumpur - Bukit Jalil","Service Residence","2","empty","2","868 sq.ft.","Partially Furnished","Parking, Playground, Swimming Pool, Security, Multipurpose hall, Gymnasium, Jogging Track","Cooking Allowed, Near KTM/LRT", "Kuala Lumpur");
    Property property5("100322212","Majestic Maxim","2021","RM 1 400 per month","Kuala Lumpur - Cheras","Service Residence","2","2","empty","2,650 sq.ft.","Not Furnished","Parking, Gymnasium, Jogging Track, Lift, Barbeque area, Security, Swimming Pool, Playground","Air-Cond, Near KTM/LRT, Cooking Allowed","Kuala Lumpur");
    Property property6("100310024","Majestic Maxim","2021","RM 1 099 per month","Kuala Lumpur - Cheras","Service Residence","2","1","2","650 sq.ft.","Partially Furnished","Security, Swimming Pool, Parking, Jogging Track, Barbeque area, Playground, Gymnasium, Lift","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property7("100310024","Majestic Maxim","2021","RM 1 099 per month","Kuala Lumpur - Cheras","Service Residence","2","1","2","650 sq.ft.","Partially Furnished","Security, Swimming Pool, Parking, Jogging Track, Barbeque area, Playground, Gymnasium, Lift","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");
    Property property8("100318578","Kepong Sentral Condominium","2007","RM 999 per month","Kuala Lumpur - Kepong","Condominium","3","1","empty","2,962 sq.ft.","Not Furnished","Security, Minimart, Playground, Squash Court, Jogging Track, Lift, Parking, Swimming Pool, Tennis Court, Gymnasium","empty","Kuala Lumpur");
    Property property9("100318535","Nuri Court","empty","RM 1 500 per month","Kuala Lumpur - Pandan Indah","Apartment","3","empty","2","900 sq.ft.","Fully Furnished","Parking, Security","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");

    // favouriteListTenant.insertAtEnd(property1);
    // favouriteListTenant.insertAtEnd(property3);
    // favouriteListTenant.insertAtEnd(property5);
    // favouriteListTenant.insertAtEnd(property6);
    // favouriteListTenant.insertAtEnd(property8);

    return favouriteListTenant;
}

Queue<Property> initializeRentRequest()
{
    Queue<Property> rentRequestList;
    // Property property1("100318535", "Nuri Court", "empty", "RM 1 500 per month", "Kuala Lumpur - Pandan Indah", "Apartment", "3", "empty", "2", "900 sq.ft.", "Fully Furnished", "Parking, Security", "Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine", "Kuala Lumpur");
    // Property property2("100318578","Kepong Sentral Condominium","2007","RM 999 per month","Kuala Lumpur - Kepong","Condominium","3","1","empty","2,962 sq.ft.","Not Furnished","Security, Minimart, Playground, Squash Court, Jogging Track, Lift, Parking, Swimming Pool, Tennis Court, Gymnasium","empty","Kuala Lumpur");
    
    // rentRequestList.enqueue(property1);
    // rentRequestList.enqueue(property2);
    return rentRequestList;
}

Queue<Property> initializeRentingHistory()
{
    Queue<Property> rentingHistoryList;

    Property property1("100258228","PV9 Residences @ Taman Melati","2022","RM 2 499 per month","Kuala Lumpur - Setapak","Service Residence","4","3","2","1100 sq.ft.","Partially Furnished","Security, Parking, Lift, Swimming Pool, Playground, Minimart, Gymnasium","Air-Cond, Cooking Allowed, Washing Machine, Near KTM/LRT","Kuala Lumpur");
    Property property2("100322212","Majestic Maxim","2021","RM 1 400 per month","Kuala Lumpur - Cheras","Service Residence","2","2","empty","2,650 sq.ft.","Not Furnished","Parking, Gymnasium, Jogging Track, Lift, Barbeque area, Security, Swimming Pool, Playground","Air-Cond, Near KTM/LRT, Cooking Allowed","Kuala Lumpur");
    Property property3("100310024","Majestic Maxim","2021","RM 1 099 per month","Kuala Lumpur - Cheras","Service Residence","2","1","2","650 sq.ft.","Partially Furnished","Security, Swimming Pool, Parking, Jogging Track, Barbeque area, Playground, Gymnasium, Lift","Air-Cond, Cooking Allowed, Near KTM/LRT, Washing Machine","Kuala Lumpur");

    property1.setTenancyProgress("a");
    property2.setTenancyProgress("r");
    property3.setTenancyProgress("refund");

    rentingHistoryList.enqueue(property1);
    // rentingHistoryList.enqueue(property2);
    // rentingHistoryList.enqueue(property3);

    return rentingHistoryList;
}


int main()
{
    // save credential

    DoublyLinkedList<Admin> adminList = initializeAdmin();
    DoublyLinkedList<Manager> managerList = initializeManager();
    DoublyLinkedList<Tenant> tenantList = initializeTenant();
    DoublyLinkedList<Property> propertyList = initializeProperty();
    DoublyLinkedList<Property> favouriteListAll = initializeFavouriteListAll();
    DoublyLinkedList<Property> favouriteListTenant = initializeFavouriteListTenant();
    Queue<Property> rentRequestList = initializeRentRequest();
    Queue<Property> rentingHistoryList =initializeRentingHistory();

    Menu::displayMenu(adminList, managerList, tenantList,propertyList, favouriteListAll, favouriteListTenant, rentRequestList, rentingHistoryList);
    return 0;
}
