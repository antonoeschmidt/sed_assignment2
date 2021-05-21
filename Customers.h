// Used to being able to include header in another header
#ifndef CUSTOMERS_H_
#define CUSTOMERS_H_

#include <string>
#include <vector>
#include "Items.h"

using namespace std;

class Customer
{
private:
    string id, name, address, phone;
    vector<string> items;
    int noOfReturns;
    bool guest;
    string customerType;

public:
    Customer();
    Customer(string id, string name, string address, string phone);
    // ~Customer();
    string getId();
    void setId(string id);
    string getName();
    void setName(string name);
    string getAddress();
    void setAddress(string address);
    string getPhone();
    void setPhone(string phone);
    string getcustomerType();
    int getNoOfReturns();
    virtual bool borrowItem(string itemId) = 0; // Pure virtual/abstract method
    virtual bool returnItem(string itemId) = 0;
    virtual string toText() = 0; // Uses to save to text
    bool isGuest();
    vector<string> getItems();
    void populateBorrowedItems(string itemId);
    void removeBorrowedItems(string itemId);

    void setcustomerType(string customerType);
};

class Regular : public Customer
{
private:
    bool guest;

public:
    Regular();
    Regular(string id, string name, string address, string phone);
    bool borrowItem(string itemId);
    bool returnItem(string itemId);
    string toText();
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
    bool borrowItem(string itemId);
    bool returnItem(string itemId);
    string toText();
};

class VIP : public Customer
{
private:
    bool guest;

public:
    VIP();
    VIP(string id, string name, string address, string phone);
    bool borrowItem(string itemId);
    bool returnItem(string itemId);
    string toText();
    // int getReward();
};

#endif
