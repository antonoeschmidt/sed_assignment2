#include <iostream>
#include "Customers.h"

using namespace std;

/* ------ CUSTOMERS ------ */
Customer::Customer() {}
Customer::Customer(string id, string name, string address, string phone)
{
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->guest = false;
    this->noOfReturns = 0;
}
string Customer::getId() { return id; }
string Customer::getName() { return name; }
string Customer::getAddress() { return address; }
string Customer::getPhone() { return phone; }
Item *Customer::getItem() { return testItem; }
int Customer::getNoOfReturns() { return noOfReturns; }
bool Customer::isGuest() { return guest; }
void Customer::setItem(Item *item)
{
    this->testItem = item;
}

// ----- Regular -----
Regular::Regular() : Customer()
{
}

Regular::Regular(string id, string name, string address, string phone) 
    : Customer(id, name, address, phone)
{
}

// ---- Guest -----
Guest::Guest() : Customer()
{
    this->guest = true;
    this->maxRental = 2;
}
Guest::Guest(string id, string name, string address, string phone)
    : Customer(id, name, address, phone)
{
    this->guest = true;
    this->maxRental = 2;
}
bool Guest::borrowItem(/* item here */)
{
    cout << "Borrow Item called" << endl;

    return false;
}

bool Guest::returnItem(/* item here */)
{
    cout << "Return Item called" << endl;

    return false;
}

bool Guest::isGuest() { return guest; }
int Guest::getMaxRental() { return maxRental; }
