// Used to being able to include header in another header
#ifndef CUSTOMERS_H_
#define CUSTOMERS_H_

#include <string>
#include "Items.h"

using namespace std;

class Customer
{
private:
    string id, name, address, phone;
    // Not the right field, but will be there untill the LinkedList is implemented
    Item *testItem;
    int noOfReturns;
    bool guest;

public:
    Customer();
    Customer(string id, string name, string address, string phone);
    // ~Customer();
    string getId();
    string getName();
    string getAddress();
    string getPhone();
    Item *getItem();
    int getNoOfReturns();
    void returnItem(/* Will have Item here as an argument */)
    {
        noOfReturns++;
        //TODO: return item
    }
    bool isGuest();
    // For testing
    void setItem(Item *item);
};

class Guest : public Customer
{
private:
    int maxRental;
    bool guest;

public:
    Guest();
    Guest(string id, string name, string address, string phone);
    int getMaxRental();
    bool isGuest();
};

#endif
