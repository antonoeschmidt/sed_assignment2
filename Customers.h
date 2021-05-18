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
    Item *testItem; // Not the right field, but will be there untill the LinkedList is implemented
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
    virtual bool borrowItem() = 0; // Pure virtual/abstract method
    virtual bool returnItem() = 0; 
    bool isGuest();
    void setItem(Item *item); // For testing
};

class Regular : public Customer
{
private:
    int maxRental;
    bool guest;

public:
    Regular();
    Regular(string id, string name, string address, string phone);
    bool borrowItem();
    bool returnItem();
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
    bool isGuest(); // does it have to be here, when it's already in Customer class?
    bool borrowItem();
    bool returnItem();
};

class VIP: public Customer
{
    private:
        int maxRental;
        bool guest;
    public: 
        VIP();
        VIP(string id, string name, string address, string phone, int reward);
        bool borrowItem();
        bool returnItem();
        int getReward();
        
};

#endif
