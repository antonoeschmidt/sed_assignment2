#include <iostream>
#include <fstream>
#include <string>
#include "Customers.h"
#include "Customers.cpp"
#include "Items.h"
#include "items.cpp"
#include "FileHandler.h"
#include "FileHandler.cpp"

using namespace std;

FileHandler fileHandler;

Item* searchItemByID(vector<Item *> items ,string input)
{
    Item* tmp = NULL;
    for (auto &i : items)
    {
        if (input == i->getId())
        {
            return i;
        }
    }
    cout << "No item found!" << endl;
    return tmp;
}

void displayItem(vector<Item *> items)
{
    cout << "----------Item List----------" << endl;
    for (auto &i : items)
    {
        cout << "ID: " << i->getId() << " | "
             << "Title:" << i->getTitle() << " | "
             << "Rental Type: " << i->getRentalType() << " | "
             << "Loan Type:" << i->getLoanType() << " | "
             << "Stock:" << i->getStock() << " | "
             << "Fee: " << i->getRentalFee() << " USD"
             << " | "
             << "Available: " << boolalpha << i->isAvaliable() << endl;
    }
    cout << "-----------------------------" << endl;
}

void displayCustomer(vector<Customer *> customers)
{
    cout << "----------Customer List----------" << endl;
    for (auto &i : customers)
    {
        cout << "ID: " << i->getId() << " | "
             << "Name:" << i->getName() << " | "
             << "Address:" << i->getAddress() << " | "
             << "Phone Number:" << i->getPhone() << endl;
        vector<string> items = i->getItems();
        if (items.size() > 0)
        {
            for (int j = 0; j < items.size(); j++)
            {
                cout << items[j] << endl;
            }
        }
    }
    cout << "-----------------------------" << endl;
}

void updateItem(Item *item, vector<Item *>itemslist)
{
    bool exit = false;
    while (!exit)
    {
        cout << "Select aspect to change:" << endl;
        cout << "1. ID: " << item->getId() << endl;
        cout << "2. Title " << item->getTitle() << endl;
        cout << "3. Loan Type: " << item->getLoanType() << endl;
        cout << "4. Stock: " << item->getStock() << endl;
        cout << "5. Rental Fee: " << item->getRentalFee() << endl;
        cout << "|0.Exit|" << endl;
        string choice, input;
        float fee;
        int option, digit;
        cin >> choice;
        try
        {
            option = stoi(choice);
        }
        catch (const invalid_argument)
        {
            if (choice == "Exit" || choice == "exit")
            {
                exit = true;
                return;
            }
            else
            {
                cerr << "Invalid input" << endl;
            }
        }
        switch (option)
        {
        case 0:
            exit = true;
            break;
        case 1:
            cout << "Enter new ID digit: ";
            int year;
            cin >> input;
            try
            {
                digit = stoi(input);
            }
            catch (const invalid_argument)
            {
                cerr << "Invalid input" << endl;
                break;
            }
            if (digit <= 100 || digit >= 999)
            {
                cerr << "Digit must be a continous three digit" << endl;
                break;
            }
            cout << "Enter year published: ";
            cin >> input;
            try
            {
                year = stoi(input);
            }
            catch (const invalid_argument)
            {
                cerr << "Invalid input" << endl;
                break;
            }
            input = "I" + to_string(digit) + "-" + to_string(year);
            item->setId(input);
            fileHandler.writeItemsFile(itemslist);
            break;
        case 2:
            cout << "Enter new title: ";
            cin.ignore(1, '\n');
            getline(cin, input);
            item->setTitle(input);
            fileHandler.writeItemsFile(itemslist);
            break;
        case 3:
            cout << "Enter loan type: ";
            cin.ignore(1, '\n');
            getline(cin, input);
            item->setLoanType(input);
            fileHandler.writeItemsFile(itemslist);
            break;
        case 4:
            cout << "Enter amount in stock: ";
            cin >> input;
            try
            {
                digit = stoi(input);
            }
            catch (const invalid_argument)
            {
                cerr << "Invalid input" << endl;
                break;
            }
            item->setStock(digit);
            fileHandler.writeItemsFile(itemslist);
            break;
        case 5:
            cout << "Enter rental fee: " << endl;
            cin >> input;
            try
            {
                fee = stof(input);
            }
            catch (const invalid_argument)
            {
                cerr << "Invalid input" << endl;
                break;
            }
            item->setRentalFee(fee);
            fileHandler.writeItemsFile(itemslist);
            break;
        default:
            cerr << "Incorrect Use";
            break;
        }
    }
}

void deleteItem(vector<Item *> items)
{
    string itemId;
    cout << "Items:" << endl;
    displayItem(items);
    cout << "Enter ID of Item that should be deleted:" << endl;
    bool found = false;
    while (!found)
    {
        cin >> itemId;
        if (itemId == "0")
            break;

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i]->getId() == itemId)
            {
                items.erase(items.begin() + i);
                found = true;
                cout << "Item with ID: " << items[i]->getId() << " deleted" << endl;
            }
        }
        if (!found)
            cout << "Item not found. Please try another item or exit by typing 0." << endl;
    }

    fileHandler.writeItemsFile(items);
}

void addItem(vector<Item *> items)
{
    enum ItemType
    {
        REC = 1,
        DIS = 2,
        GA = 3
    };
    string title, digit, id, year, loan, genre;
    bool borrowed = false;
    float fee;
    int stock, type;
    cin.ignore(1, '\n');
    cout << "Enter Title: " << endl;
    getline(cin, title);
    cout << "Enter Item 3-digit code: " << endl;
    cin >> digit;
    while(digit.size() != 3){
        cerr << "Incorrect code format" << endl;
        cout << "Enter Item 3-digit code: " << endl;
        cin >> digit;
    }
    cout << "Enter year published: " << endl;
    cin >> year;
    while(year.size() != 4){
        cerr << "year has to have format yyyy" << endl;
        cout << "Enter year published: " << endl;
        cin >> year;
    }
    id = "I" + digit + "-" + year;
    cout << "Enter loan type: " << endl;
    cin >> loan;
    while(loan != "2-day" && loan != "1-week"){
        cerr << "loan has to be either '2-day' or '1-week'" << endl;
        cout << "Enter loan type: " << endl;
        cin >> loan;
    }
    cout << "Enter amount: " << endl;
    cin >> stock;
    cout << "Enter rental fee: " << endl;
    cin >> fee;
    cout << "Select Item Type: " << endl
         << "(1) Record" << endl
         << "(2) DVD" << endl
         << "(3) Game" << endl;
    cin >> type;
    while(type != DIS && type != REC && type != GA){
        cerr << "Incorrect Item Type" << endl;
        cout << "Select Item Type: " << endl
        << "(1) Record" << endl
        << "(2) DVD" << endl
        << "(3) Game" << endl;
        cin >> type;
    }
    if (type == DIS)
    {
        cout << "Enter genre: ";
        cin >> genre;
        DVD *disc = new DVD(id, title, loan, stock, fee, genre);
        items.push_back(disc);
        fileHandler.writeItemsFile(items);
        delete disc;
    }
    if (type == REC)
    {
        cout << "Enter genre: ";
        cin >> genre;
        Record *record = new Record(id, title, loan, stock, fee, genre);
        items.push_back(record);
        fileHandler.writeItemsFile(items);
        delete record;
    }
    if (type == GA)
    {
        VideoGames *videoGame = new VideoGames(id, title, loan, stock, fee);
        items.push_back(videoGame);
        fileHandler.writeItemsFile(items);
        delete videoGame;
    }
}



void addCustomer(vector<Customer *> Customers)
{
    enum CustomerType
    {
        VI = 1,
        REG = 2,
        GUE = 3
    };
    string id;
    string name;
    string address;
    string phone;
    int noOfReturn;
    bool guest;
    int type;
    cout << "Enter Id: " << endl;
    cin >> id;
    while(id.size() != 3){
        cerr << "ID must be 3-digit" << endl;
        cin >> id;
    }
    cout << "Enter Name: " << endl;
    cin >> name;
    cout << "Enter the address: " << endl;
    cin >> address;
    cout << "Enter Phone number " << endl;
    cin >> phone;
    cout << "Number of Returns " << endl;
    cin >> noOfReturn;

    cout << "Select Customer Type: " << endl
         << "(1) VIP" << endl
         << "(2) Regular" << endl
         << "(3) Guest" << endl;
    cin >> type;
    while(type != VI && type != REG && type != GUE){
        cerr << "Incorrect Customer Type" << endl;
        cout << "Select Customer Type: " << endl
         << "(1) VIP" << endl
         << "(2) Regular" << endl
         << "(3) Guest" << endl;
        cin >> type;        
    }
    if (type == VI)
    {
<<<<<<< HEAD
=======
        //cout << "Enter  ";
        //    cin >> genre;
>>>>>>> 002ebcb64a962a99e563ef82c4d5b52efa8fc7ce
        VIP *vip = new VIP(id, name, address, phone);
        Customers.push_back(vip);
        fileHandler.writeCustomersFile(Customers);
        delete vip;
    }
    if (type == REG)
    {
<<<<<<< HEAD
    Regular *reg = new Regular(id, name, address, phone);
=======
        //    cout << "Enter genre: ";
        //    cin >> genre;
        Regular *reg = new Regular(id, name, address, phone);
>>>>>>> 002ebcb64a962a99e563ef82c4d5b52efa8fc7ce
        Customers.push_back(reg);
        fileHandler.writeCustomersFile(Customers);
        delete reg;
    }
    if (type == GUE)
    {
        Guest *guest = new Guest(id, name, address, phone);
        Customers.push_back(guest);
        fileHandler.writeCustomersFile(Customers);
        delete guest;
    }

    fileHandler.writeCustomersFile(Customers);
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
    cout << "0. Exit" << endl;
}

bool handleItem()
{
    vector<Item *> items;
    bool exit = false;
    while (!exit)
    {
        items = fileHandler.readItemsFile();

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
        }
        if (tmp >= 0 && tmp <= 3)
        {
            switch (tmp)
            {
            case 0:
                exit = true;
                return true;
            case 1:
                addItem(items);
                break;
            case 2:
                deleteItem(items);
                break;
            case 3:
                displayItem(items);
                cout << "Enter ID of item to update: ";
                cin >> a;
                if(searchItemByID(items,a) != NULL)
                {
                    updateItem(searchItemByID(items,a),items);
                }
                break;
            }
        }
    }
    return false;
}

bool handleCustomer()
{
    cout << "Choose action:" << endl
         << "(1) Add" << endl
         << "(2) Update" << endl
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
            break;
        case 1:
            // addItem();
            break;
        case 2:
            break;
        }
    }
    return false;
}

void rentItem()
{
    vector<Customer *> customers = fileHandler.readCustomerFile();
    vector<Item *> items = fileHandler.readItemsFile();
    string customerId, itemId;
    bool found = false;

    displayItem(items);
    cout << "Enter ID of Item that you wants to be rented: ";
    while (!found)
    {
        bool outOfStock = false;
        cin >> itemId;
        if (itemId == "0")
            break;

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i]->getId() == itemId)
            {
                if (items[i]->getStock() < 1)
                {
                    cout << "Item is unfortunately out of stock. Please choose another: ";
                    outOfStock = true;
                }
                else
                {
                    itemId = items[i]->getId();
                    found = true;
                    cout << "Item with ID: " << items[i]->getId() << " chosen" << endl;
                }
            }
        }
        if (!found && !outOfStock)
            cout << "Item not found. Please try another item or exit by typing 0." << endl;
    }

    found = false;

    displayCustomer(customers);
    cout << "Enter ID of the customer that will rent this item: ";
    while (!found)
    {
        bool success = false;
        cin >> customerId;
        if (customerId == "0")
            break;

        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i]->getId() == customerId)
            {
                success = customers[i]->borrowItem(itemId);
                if (success)
                {
                    found = true;
                    for (int i = 0; i < items.size(); i++)
                    {
                        if (items[i]->getId() == itemId)
                        {
                            items[i]->setStock(items[i]->getStock() - 1);
                        }
                    }
                }
                else
                {
                    cout << "Renting was unsucessful. Please try again." << endl;
                }
            }
        }
        // if (!found && !success)
        //     cout << "Item not found. Please try another item or exit by typing 0." << endl;
    }
    fileHandler.writeCustomersFile(customers);
    fileHandler.writeItemsFile(items);
}

void input()
{
    bool exit = false;
    while (!exit)
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
        case 0:
            exit = true;
            break;
        case 1:
            handleItem();
            break;
        case 2:
            handleCustomer();
            break;
        case 4:
            rentItem();
            break;
        case 6:
            displayItem(fileHandler.readItemsFile());
            break;
        default:
            cerr << "Incorrect Use";
            break;
        }
    }
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

    // FileHandler fileHandler;
    // vector<Item *> items;
    // vector<Customer *> customers;

    // customers = fileHandler.readCustomerFile();
    // displayCustomer(customers);

    // items = fileHandler.readItemsFile();
    // displayItem(items);

    // //UI
    // items = fileHandler.readItemsFile();
    input();

    return 0;
}
