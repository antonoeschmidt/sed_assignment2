#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Customers.h"
#include "Customers.cpp"
#include "Items.h"
#include "items.cpp"
#include "FileHandlar.h"
#include "FileHandlar.cpp"

using namespace std;

void input()
{
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
    if (option >= 1 && option <= 10)
    {
        switch (option)
        {
        case 1:;
        case 2:;
        case 3:;
        case 4:;
        case 5:;
        case 6:;
        case 7:;
        case 8:;
        case 9:;
        case 10:;
        }
    }
    else
    {
        cerr << "Invalid Input";
    }
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
    input();
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

void populateItems(vector<Item*> items) {

    // Call fileHandler to read items.txt
    // which should return an array of string which we will iterate over

    string items[5];
    for (int i = 0; i < items.size(); i++)
    {
        /* code */
    }
    



}

int main(int argc, char *argv[])
{

    vector<Item*> items;
    vector<Customer*> customers;

    populateItems(items);


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
    Menu();

    // Tests
    Test();

    return 0;
}
