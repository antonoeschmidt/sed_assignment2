#include <iostream>
#include <vector>
#include "Customers.h"
#include "Customers.cpp"

using namespace std;

<<<<<<< HEAD
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

int Guest::getMaxRental() { return maxRental; }



=======
>>>>>>> master
int main()
{
    vector<Customer*> guestList;

    Guest *guest1 = new Guest("11", "Guest Doggy", "District 14", "0123 012 234");
    Regular *reg1 = new Regular("11", "Regular Anton", "District 4", "0123 012 234");

    guestList.push_back(guest1);
    guestList.push_back(reg1);

    cout << "Output of begin and end: ";

    for (int i = 0; i < guestList.size(); i++)
    {
        cout << guestList[i]->getName() << endl;
    }

    return 0;
}
