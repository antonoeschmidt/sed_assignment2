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

// ----- Regular -----
Regular::Regular() : Customer()
{
    this->guest = false;
}

Regular::Regular(string id, string name, string address, string phone)
    : Customer(id, name, address, phone)
{
    this->guest = false;
}

bool Regular::borrowItem()
{
    // cout << "Borrow Item called" << item->getTitle() << endl;

    return false;
}

bool Regular::returnItem()
{
    // cout << "Return Item called" << item->getTitle() << endl;

    return false;
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

bool Guest::borrowItem()
{
    if(getBorrowedList().size() > 2){
        cerr << "guest has already borrowed too many items" << endl;
    }
    // if(this->getNoOfReturns() > this->getMaxRental()){
    //     cerr << "guest has already borrowed too many items" << endl;
    // }
    // else{
    //     cout << "Borrow Item called" << getTitle() << endl;
    // }
    return false;
}

bool Guest::returnItem()
{
    // cout << "Return Item called" << item->getTitle() << endl;

    return false;
}

int Guest::getMaxRental() { return maxRental; }

// ----- VIP -----
VIP::VIP() : Customer()
{
}
VIP::VIP(string id, string name, string address, string phone, int reward)
    : Customer(id, name, address, phone)
{
    this->reward = reward;
}

bool VIP::borrowItem()
{
    // cout << "Borrow Item called" << item->getTitle() << endl;

    return false;
}

bool VIP::returnItem()
{
    // cout << "Return Item called" << item->getTitle() << endl;

    return false;
}

int VIP::getReward() {return reward;}
