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
int Customer::getNoOfReturns() { return noOfReturns; }
bool Customer::isGuest() { return guest; }
vector<string> Customer::getItems() { return items; }
void Customer::populateBorrowedItems(string itemId)
{
    this->items.push_back(itemId);
}
string Customer::getcustomerType()
{
    return this->customerType;
}

void Customer::setcustomerType(string customerType)
{
    this->customerType = customerType;
}
void Customer::removeBorrowedItems(string itemId)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (itemId.substr(0,9) == items[i].substr(0,9))
        {
            items.erase(items.begin() + i);
            cout << "Item with ID: " << items[i] << " returned" << endl;
        }
    }
}

void Customer::setId(string id)
{
    this->id = id;
}

void Customer::setName(string name)
{
    this->name = name;
}

void Customer::setAddress(string address)
{
    this->address = address;
}

void Customer::setPhone(string phone)
{
    this->phone = phone;
}

// ----- Regular -----
Regular::Regular() : Customer()
{
    this->guest = false;
    this->setcustomerType("Regular");
}

Regular::Regular(string id, string name, string address, string phone)
    : Customer(id, name, address, phone)
{
    this->guest = false;
    this->setcustomerType("Regular");
}

bool Regular::borrowItem(string itemId)
{
    this->populateBorrowedItems(itemId);
    return true;
}

bool Regular::returnItem(string itemId)
{
    this->removeBorrowedItems(itemId);
    return true;
}

string Regular::toText()
{
    return this->getId() + "," + this->getName() + "," + this->getAddress() + "," + this->getPhone() + "," + to_string(this->getItems().size()) + ",Regular";
}

// -- VIP -- //
VIP::VIP() : Customer()
{
    this->guest = false;
    this->setcustomerType("VIP");
}
VIP::VIP(string id, string name, string address, string phone)
    : Customer(id, name, address, phone)
{
    this->guest = false;
    this->setcustomerType("VIP");
}
bool VIP::borrowItem(string itemId)
{
    this->populateBorrowedItems(itemId);
    return true;
}
bool VIP::returnItem(string itemId)
{
    this->removeBorrowedItems(itemId);

    return false;
}
string VIP::toText()
{
    return this->getId() + "," + this->getName() + "," + this->getAddress() + "," + this->getPhone() + "," + to_string(this->getItems().size()) + ",VIP";
}

// ---- Guest -----
Guest::Guest() : Customer()
{
    this->guest = true;
    this->maxRental = 2;
    this->setcustomerType("Guest");
}
Guest::Guest(string id, string name, string address, string phone)
    : Customer(id, name, address, phone)
{
    this->guest = true;
    this->maxRental = 2;
    this->setcustomerType("Guest");
}
bool Guest::borrowItem(string itemId)
{
    if (this->getItems().size() >= this->getMaxRental())
    {
        cout << "Max number of rentals reached. Please return an item before borrowing a new." << endl;
        return false;
    }
    else
    {
        this->populateBorrowedItems(itemId);
        return true;
    }
}

bool Guest::returnItem(string itemId)
{
    this->removeBorrowedItems(itemId);

    return false;
}
bool Guest::isGuest() { return guest; }
int Guest::getMaxRental() { return maxRental; }

string Guest::toText()
{
    return this->getId() + "," + this->getName() + "," + this->getAddress() + "," + this->getPhone() + "," + to_string(this->getItems().size()) + ",Guest";
}