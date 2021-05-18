#include <iostream>
#include <vector>
#include "Customers.h"
#include "Customers.cpp"

using namespace std;

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
