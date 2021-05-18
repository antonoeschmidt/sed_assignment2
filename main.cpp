#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Customers.h"
#include "Customers.cpp"
#include "Items.h"
#include "items.cpp"

using namespace std;

/* ------ CUSTOMERS ------ */
// Customer::Customer() {}
// Customer::Customer(string id, string name, string address, string phone)
// {
//     this->id = id;
//     this->name = name;
//     this->address = address;
//     this->phone = phone;
//     this->guest = false;
//     this->noOfReturns = 0;
// }
// string Customer::getId() { return id; }
// string Customer::getName() { return name; }
// string Customer::getAddress() { return address; }
// string Customer::getPhone() { return phone; }
// Item *Customer::getItem() { return testItem; }
// int Customer::getNoOfReturns() { return noOfReturns; }
// bool Customer::isGuest() { return guest; }
// void Customer::setItem(Item *item)
// {
//     this->testItem = item;
// }
// // ---- Guest -----
// Guest::Guest() : Customer()
// {
//     this->guest = true;
//     this->maxRental = 2;
// }
// Guest::Guest(string id, string name, string address, string phone)
//     : Customer(id, name, address, phone)
// {
//     this->guest = true;
//     this->maxRental = 2;
// }
// bool Guest::borrowItem(/* item here */)
// {
//     cout << "Borrow Item called" << endl;

//     return false;
// }

// bool Guest::returnItem(/* item here */)
// {
//     cout << "Return Item called" << endl;

//     return false;
// }

// bool Guest::isGuest() { return guest; }
// int Guest::getMaxRental() { return maxRental; }

bool addItem()
{
    string Title;
    cout << "Enter Title: ";
    cin >> Title;
    string id;
    cout << "Enter Item 3-digit code: ";


    cout << "Select Item Type: " << endl
         << "(1) Record" << endl
         << "(2) DVD" << endl
         << "(3) Game" << endl;
    string type;
}

void Menu()
{
    cout << "Welcome to Oggy's video store" << endl;
    cout << "Enter an option below." << endl;
    cout << "1. Add a new item, update or delete an existing item" << endl;
    cout << "2. Add new customer or update an existing customer" << endl;
    cout << "3. Promote an existing customer" << endl;
    cout << "4. Rent an item" << endl;
    cout << "5. Return an item" << endl;
    cout << "6. Display all items" << endl;
    cout << "7. Display out-of-stock items" << endl;
    cout << "8. Display all customers" << endl;
    cout << "9. Display group of customers" << endl;
    cout << "10. Search items or customers" << endl;
    cout << "Exit" << endl;
}

bool auditem()
{
    cout << "Choose action:" << endl
         << "(1) Add" << endl
         << "(2) Delete" << endl
         << "(3) Update" << endl
         << "(0) Back to menu" << endl;
    string a;
    int tmp;
    cin >> a;
    try
    {
        tmp = stoi(a);
    }
    catch (const invalid_argument)
    {
        cerr << "Invalid input";
        return false;
    }
    if (tmp >= 0 && tmp <= 3)
    {
        switch (tmp)
        {
        case 0:
            return true;
        case 1:
            addItem();
        case 2:;
        case 3:;
        }
    }
    return false;
}

void input()
{
    Menu();
    string choice;
    int option;
    cin >> choice;
    try
    {
        option = stoi(choice);
    }
    catch (const invalid_argument)
    {
        if (choice == "Exit" || choice == "exit")
        {
            //Exit function here
            return;
        }
        else
        {
            cerr << "Invalid input";
        }
    }
    switch (option)
    {
    case 1:
        bool tmp;
        do
        {
            tmp = auditem();
        } while (tmp != true);
        input();
        break;
    case 2:;
    default:
        cerr << "Incorrect Use";
    }
}


void Test()
{
    Item *item1 = new Item("123", "hej", "book", 1, 100, false);
    cout << item1->getId() << endl;
    cout << "isBorrowed: " << boolalpha << item1->getBorrowed() << endl;
    item1->setBorrowed(true);
    cout << "isBorrowed: " << boolalpha << item1->getBorrowed() << endl;

    // Customers
    // Customer base class cant be declared with abstract methods
    // Customer *cus1 = new Customer("10", "Oggy", "District 12", "0702 602 509");
    // cout << "Is guest?: " << boolalpha << cus1->isGuest() << endl;
    // cus1->setItem(item1);
    // Item *item2 = cus1->getItem();
    // cout << item2->getTitle() << endl;

    Guest *guest1 = new Guest("11", "Doggy", "District 14", "0123 012 234");
    cout << "Is guest?: " << boolalpha << guest1->isGuest() << endl;
    cout << "Max rental: " << boolalpha << guest1->getMaxRental() << endl;

    Regular *reg1 = new Regular("11", "RegDoggy", "District 1", "0123 012 234");
    cout << "Is guest?: " << boolalpha << reg1->isGuest() << endl;
}

int main(int argc, char *argv[])
{
    // Checks if the program is executed in the correct format
    if (argc != 2)
    {
        cout << "Invalid amount of argument";
        return -1;
    }

    //Opening the file and checking if it's opened properly
    fstream infile(argv[1]);
    if (!infile)
    {
        cerr << "Error opening file" << endl;
        return -1;
    }
    //Declaring Vectors
    vector<Item *> ItemList;
    vector<Guest *> GuestList;
    //UI
    input();

    // Tests
    Test();

    return 0;
}
