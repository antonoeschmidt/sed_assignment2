// Used to being able to include header in another header
#ifndef CUSTOMERS_H_
#define CUSTOMERS_H_

#include <string>
#include <vector>
#include "Items.h"
#include <vector>

using namespace std;

class Customer
{
private:
    string id, name, address, phone;
    vector<string> items;
    int noOfReturns;
    vector<Item*> BorrowedList;
    bool guest;

public:
    Customer();
    Customer(string id, string name, string address, string phone);
    // ~Customer();
    string getId();
    string getName();
    string getAddress();
    string getPhone();
    int getNoOfReturns();
    vector<Item*> getBorrowedList(){ return BorrowedList;};
    virtual bool borrowItem() = 0; // Pure virtual/abstract method
    virtual bool returnItem() = 0;
    bool isGuest();
    vector<string> getItems();
    void populateBorrowedItems(string itemId);
};

class Regular : public Customer
{
private:
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
    bool borrowItem();
    bool returnItem();
};

class VIP : public Customer
{
    private:
        bool guest;
        int reward;
    public: 
        VIP();
        VIP(string id, string name, string address, string phone, int reward);
        bool borrowItem();
        bool returnItem();
        int getReward();
        
};

#endif
