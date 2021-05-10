#ifndef CUSTOMERS_H_
#define CUSTOMERS_H_

#include <string>
#include "Items.h"

using namespace std;

class Customer
{
private:
    string id, name, address, phone;
    Item* testItem;
public:
    Customer();
    Customer(string id, string name, string address, string phone);
    // ~Customer();
    string getId();
    string getName();
    string getAddress();
    string getPhone();
    Item* getItem();
    void setItem(Item *item);
};

#endif
