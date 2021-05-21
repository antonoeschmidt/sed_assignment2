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
string itemFile;
string customerFile;

Item *searchItemByID(vector<Item *> items, string input)
{
    Item *tmp = NULL;
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

Customer *searchCustomerByID(vector<Customer *> customers, string input)
{
    Customer *tmp = NULL;
    for (auto &i : customers)
    {
        if (input == i->getId())
        {
            return i;
        }
    }
    cout << "No customer found!" << endl;
    return tmp;
}

Customer *searchCustomerByName(vector<Customer *> customers, string input)
{
    Customer *tmp = NULL;
    for (auto &i : customers)
    {
        if (input == i->getName())
        {
            return i;
        }
    }
    cout << "No customer found!" << endl;
    return tmp;
}

Item *searchItemByName(vector<Item *> items, string input)
{
    Item *tmp = NULL;
    for (auto &i : items)
    {
        if (input == i->getTitle())
        {
            return i;
        }
    }
    cout << "No item found!" << endl;
    return tmp;
}

void displayOutOfStockItem(vector<Item *> items)
{

    cout << "----------Out of Stock Item List----------" << endl;
    int numOutOfStock = 0; // initialize # of items out of stock
    for (auto &i : items) // loop through items 
    {
        if (i->getStock() == 0) // if number of item i in stock is zero, it's out of stock
        {
            numOutOfStock++; // increment # of items out of stock
            // show info about item i, which is out of stock
            cout << "ID: " << i->getId() << " | " 
                 << "Title:" << i->getTitle() << " | "
                 << "Rental Type: " << i->getRentalType() << " | "
                 << "Loan Type:" << i->getLoanType() << " | "
                 << "Stock:" << i->getStock() << " | "
                 << "Fee: " << i->getRentalFee() << " USD"
                 << " | "
                 << "Available: " << boolalpha << i->isAvaliable() << endl;
        }
        else
        {
            continue;
        }
    }
    if (numOutOfStock == 0) // show the following message if no items are out of stock
    {
        cout << "There are no items out of stock." << endl;
    }
    cout << "------------------------------------------" << endl;
}

void displayItem(vector<Item *> items)
{
    cout << "----------Item List----------" << endl;
    // loop through all items and show information about them
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
    // loop thorugh all customers and show information about them
    for (auto &i : customers)
    {
        cout << "ID: " << i->getId() << " | "
             << "Name: " << i->getName() << " | "
             << "Address: " << i->getAddress() << " | "
             << "Phone Number: " << i->getPhone() << " | "
             << "Account Type: " << i->getcustomerType() << endl;
        vector<string> items = i->getItems();
        if (items.size() > 0) // if customer has borrowed items, show them
        {
            for (int j = 0; j < items.size(); j++)
            {
                cout << items[j] << endl;
            }
        }
    }
    cout << "-----------------------------" << endl;
}

void displayCustomerGroup(vector<Customer *> customers)
{
    cout << "==========Guests==========" << endl;
    for (auto &i : customers) // loop through all customers
    {
        if (i->getcustomerType() == "Guest") // check if they're guests
        {
            // show their information
            cout << "ID: " << i->getId() << " | "
                 << "Name:" << i->getName() << " | "
                 << "Address:" << i->getAddress() << " | "
                 << "Phone Number:" << i->getPhone() << " | "
                 << "Account Type: " << i->getcustomerType() << endl;
            vector<string> items = i->getItems();
            if (items.size() > 0) // if they borrowed some items, show them
            {
                for (int j = 0; j < items.size(); j++)
                {
                    cout << items[j] << endl;
                }
            }
        }
    }
    cout << "==========================" << endl;
    cout << "*********Regulars*********" << endl;
    // the rest of the code is the same for regular and VIP customers
    for (auto &i : customers) // 
    {
        if (i->getcustomerType() == "Regular")
        {
            cout << "ID: " << i->getId() << " | "
                 << "Name:" << i->getName() << " | "
                 << "Address:" << i->getAddress() << " | "
                 << "Phone Number:" << i->getPhone() << " | "
                 << "Account Type: " << i->getcustomerType() << endl;
            vector<string> items = i->getItems();
            if (items.size() > 0)
            {
                for (int j = 0; j < items.size(); j++)
                {
                    cout << items[j] << endl;
                }
            }
        }
    }
    cout << "***************************" << endl;
    cout << "____________VIP____________" << endl;
    for (auto &i : customers)
    {
        if (i->getcustomerType() == "VIP")
        {
            cout << "ID: " << i->getId() << " | "
                 << "Name:" << i->getName() << " | "
                 << "Address:" << i->getAddress() << " | "
                 << "Phone Number:" << i->getPhone() << " | "
                 << "Account Type: " << i->getcustomerType() << endl;
            vector<string> items = i->getItems();
            if (items.size() > 0)
            {
                for (int j = 0; j < items.size(); j++)
                {
                    cout << items[j] << endl;
                }
            }
        }
    }
    cout << "___________________________" << endl;
}

void updateCustomer(Customer *customer, vector<Customer *> customers){
    bool exit = false;
    while (!exit)
    {
        cout << "Select aspect to change:" << endl;
        cout << "1. ID: " << customer->getId() << endl;
        cout << "2. Name " << customer->getName() << endl;
        cout << "3. Address: " << customer->getAddress() << endl;
        cout << "4. Phone number: " << customer->getPhone() << endl; 
        cout << "|0.Exit|" << endl;        
        string choice, input;
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
            return;
        case 1:
            cout << "Enter new ID digit: ";
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
            if (input.size() != 3)
            {
                cerr << "ID must be 3-digit" << endl;
                break;
            }
            customer->setId(input);
            fileHandler.writeCustomersFile(customers, customerFile);
            break;
        case 2:
            cout << "Enter new name: ";
            cin >> input;
            customer->setName(input);
            fileHandler.writeCustomersFile(customers, customerFile);
            break;
        case 3:
            cout << "Enter new address: ";
            cin >> input;
            customer->setAddress(input);
            fileHandler.writeCustomersFile(customers, customerFile);
            break;
        case 4:
            cout << "Enter new phone number: ";
            cin >> input;
            customer->setPhone(input);
            fileHandler.writeCustomersFile(customers, customerFile);
            break;
        default:
            cerr << "Incorrect Use";
            break;
        }
    }
}

void updateItem(Item *item, vector<Item *> itemslist)
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
            if (input.size() != 3)
            {
                cerr << "ID must be 3-digit" << endl;
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
            fileHandler.writeItemsFile(itemslist, itemFile);
            break;
        case 2:
            cout << "Enter new title: ";
            cin.ignore(1, '\n');
            getline(cin, input);
            item->setTitle(input);
            fileHandler.writeItemsFile(itemslist, itemFile);
            break;
        case 3:
            cout << "Enter loan type: ";
            cin.ignore(1, '\n');
            getline(cin, input);
            item->setLoanType(input);
            fileHandler.writeItemsFile(itemslist, itemFile);
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
            fileHandler.writeItemsFile(itemslist, itemFile);
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
            fileHandler.writeItemsFile(itemslist, itemFile);
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

    fileHandler.writeItemsFile(items, itemFile);
}

void searchItem(vector<Item *> items)
{
    string input;
    int choice;
    cout << "Choose search method" << endl;
    cout << "1. Search by ID" << endl;
    cout << "2. Search by Name" << endl;
    cout << "0. Exit" << endl;
    cin >> input;

    try
    {
        choice = stoi(input);
    }
    catch (const invalid_argument)
    {
        cerr << "Invalid Item Type";
        return;
    }
    if (choice == 1)
    {
        Item *tmp = NULL;
        cout << "Enter ID: ";
        cin >> input;
        tmp = searchItemByID(items, input);
        if (tmp != NULL)
        {
            cout << "ID: " << tmp->getId() << " | "
                 << "Title:" << tmp->getTitle() << " | "
                 << "Rental Type: " << tmp->getRentalType() << " | "
                 << "Loan Type:" << tmp->getLoanType() << " | "
                 << "Stock:" << tmp->getStock() << " | "
                 << "Fee: " << tmp->getRentalFee() << " USD"
                 << " | "
                 << "Available: " << boolalpha << tmp->isAvaliable() << endl;
            return;
        }
    }
    if (choice == 2)
    {
        Item *tmp = NULL;
        cout << "Enter name: ";
        cin.ignore(1, '\n');
        getline(cin, input);
        tmp = searchItemByName(items, input);
        if (tmp != NULL)
        {
            cout << "ID: " << tmp->getId() << " | "
                 << "Title:" << tmp->getTitle() << " | "
                 << "Rental Type: " << tmp->getRentalType() << " | "
                 << "Loan Type:" << tmp->getLoanType() << " | "
                 << "Stock:" << tmp->getStock() << " | "
                 << "Fee: " << tmp->getRentalFee() << " USD"
                 << " | "
                 << "Available: " << boolalpha << tmp->isAvaliable() << endl;
            return;
        }
    }
    if (choice == 0)
    {
        return;
    }
    return;
}

void addItem(vector<Item *> items)
{
    enum ItemType
    {
        REC = 1,
        DIS = 2,
        GA = 3
    };
    string title, id_code, id, year, loan, genre, item_type;
    bool borrowed = false;
    float fee;
    int stock, item_type_int, id_code_int, year_int;
    cin.ignore(1, '\n');
    cout << "Enter Title: " << endl;
    getline(cin, title);
    cout << "Enter Item 3-digit code: " << endl;
    cin >> id_code;
    try
    {
        id_code_int = stoi(id_code);
    }
    catch (const invalid_argument)
    {
        cerr << "Invalid input" << endl;
        return;
    }
    while (id_code.size() != 3)
    {
        cerr << "Incorrect code format" << endl;
        cout << "Enter Item 3-digit code: " << endl;
        cin >> id_code;
    }
    cout << "Enter year published: " << endl;
    cin >> year;
    try
    {
        year_int = stoi(year);
    }
    catch (const invalid_argument)
    {
        cerr << "Invalid year" << endl;
        return;
    }
    while (year.size() != 4)
    {
        cerr << "year has to have format yyyy" << endl;
        cout << "Enter year published: " << endl;
        cin >> year;
        try
        {
            year_int = stoi(year);
        }
        catch (const invalid_argument)
        {
            cerr << "Invalid year";
            return;
        }
    }
    id = "I" + id_code + "-" + year;
    cout << "Enter loan type: " << endl;
    cin >> loan;
    while (loan != "2-day" && loan != "1-week")
    {
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
    cin >> item_type;
    try
    {
        item_type_int = stoi(item_type);
    }
    catch (const invalid_argument)
    {
        cerr << "Invalid Item Type";
        return;
    }
    while (item_type_int != DIS && item_type_int != REC && item_type_int != GA)
    {
        cerr << "Incorrect Item Type" << endl;
        cout << "Select Item Type: " << endl
             << "(1) Record" << endl
             << "(2) DVD" << endl
             << "(3) Game" << endl;
        cin >> item_type;
        try
        {
            item_type_int = stoi(item_type);
        }
        catch (const invalid_argument)
        {
            cerr << "Invalid Item Type";
            return;
        }
    }
    if (stoi(item_type) == DIS)
    {
        cout << "Enter genre: ";
        cin >> genre;
        DVD *disc = new DVD(id, title, loan, stock, fee, genre);
        items.push_back(disc);
        fileHandler.writeItemsFile(items, itemFile);
        delete disc;
    }
    if (stoi(item_type) == REC)
    {
        cout << "Enter genre: ";
        cin >> genre;
        Record *record = new Record(id, title, loan, stock, fee, genre);
        items.push_back(record);
        fileHandler.writeItemsFile(items, itemFile);
        delete record;
    }
    if (stoi(item_type) == GA)
    {
        VideoGames *videoGame = new VideoGames(id, title, loan, stock, fee);
        items.push_back(videoGame);
        fileHandler.writeItemsFile(items, itemFile);
        delete videoGame;
    }
}


//Search function for customer
void searchCustomer(vector<Customer *> customers)
{
    string input;
    int choice;
    cout << "Choose search method" << endl;
    cout << "1. Search by ID" << endl;
    cout << "2. Search by Name" << endl;
    cout << "0. Exit" << endl;
    cin >> input;


    // Error handling
    try
    {
        choice = stoi(input);
    }
    catch (const invalid_argument)
    {
        cerr << "Invalid Item Type";
        return;
    }
    if (choice == 1)
    {
        Customer *tmp = NULL;
        cout << "Enter ID: ";
        cin >> input;
        tmp = searchCustomerByID(customers, input);
        //If none is found, skip
        if (tmp != NULL)
        {
            cout << "ID: " << tmp->getId() << " | "
                 << "Name:" << tmp->getName() << " | "
                 << "Address:" << tmp->getAddress() << " | "
                 << "Phone Number:" << tmp->getPhone() << " | "
                 << "Account Type: " << tmp->getcustomerType() << endl;
            return;
        }
    }
    if (choice == 2)
    {
        Customer *tmp = NULL;
        cout << "Enter name: ";
        cin.ignore(1, '\n');
        getline(cin, input);
        tmp = searchCustomerByName(customers, input);
        if (tmp != NULL)
        {
            cout << "ID: " << tmp->getId() << " | "
                 << "Name:" << tmp->getName() << " | "
                 << "Address:" << tmp->getAddress() << " | "
                 << "Phone Number:" << tmp->getPhone() << " | "
                 << "Account Type: " << tmp->getcustomerType() << endl;
            return;
        }
    }
    if (choice == 0)
    {
        return;
    }
    return;
}



void addCustomer(vector<Customer *> customers)
{
    enum CustomerType
    {
        VI = 1,
        REG = 2,
        GUE = 3
    };
    string id, name, address, phone, type;
    int noOfReturn, id_int, type_int;
    bool guest;
    cout << "Enter Id: " << endl;
    cin >> id;
    try
    {
        id_int = stoi(id);
    }
    catch (const invalid_argument)
    {
        cerr << "Invalid ID";
        return;
    }
    while (id.size() != 3)
    {
        cerr << "ID must be 3-digit" << endl;
        cin >> id;
        try
        {
            id_int = stoi(id);
        }
        catch (const invalid_argument)
        {
            cerr << "Invalid ID";
        }
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
    try
    {
        type_int = stoi(type);
    }
    catch (const invalid_argument)
    {
        cerr << "Invalid Type";
        return;
    }
    while (type_int != VI && type_int != REG && type_int != GUE)
    {
        cerr << "Incorrect Customer Type" << endl;
        cout << "Select Customer Type: " << endl
             << "(1) VIP" << endl
             << "(2) Regular" << endl
             << "(3) Guest" << endl;
        cin >> type;
    }

    //The constructor called  corresponds to the input
    if (type_int == VI)
    {
        VIP *vip = new VIP(id, name, address, phone);
        customers.push_back(vip);
        fileHandler.writeCustomersFile(customers, customerFile);
        delete vip;
    }
    if (type_int == REG)
    {
        Regular *reg = new Regular(id, name, address, phone);
        customers.push_back(reg);
        fileHandler.writeCustomersFile(customers, customerFile);
        delete reg;
    }
    if (type_int == GUE)
    {
        Guest *guest = new Guest(id, name, address, phone);
        customers.push_back(guest);
        fileHandler.writeCustomersFile(customers, customerFile);
        delete guest;
    }
}


// Printing out menu
void Menu()
{
    cout << "" << endl;
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


//Item related
bool handleItem()
{
    vector<Item *> items;
    bool exit = false;
    while (!exit)
    {
        items = fileHandler.readItemsFile(itemFile);
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
                if (searchItemByID(items, a) != NULL)
                {
                    updateItem(searchItemByID(items, a), items);
                }
                break;
            }
        }
    }
    return false;
}


//Customer related 
bool handleCustomer()
{
    vector<Customer *> customers;
    bool exit = false;
    while (!exit)
    {
        customers = fileHandler.readCustomerFile(customerFile);
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
                exit = true;
                return true;
                break;
            case 1:
                addCustomer(customers);
                break;
            case 2:
                displayCustomer(customers);
                cout << "Enter ID of customer to update: ";
                cin >> a;
                if (searchCustomerByID(customers, a) != NULL)
                {
                    updateCustomer(searchCustomerByID(customers, a), customers);
                }
                break;
            }
        }
    }
    return false;
}

void returnItem()
{
    vector<Customer *> customers = fileHandler.readCustomerFile(customerFile);
    vector<Item *> items = fileHandler.readItemsFile(itemFile);
    vector<string> customerItems;
    Customer *customer;
    string customerId, itemId;
    bool found = false;

    displayCustomer(customers);
    cout << "Enter ID of the customer that will return an item: ";
    while (!found)
    {
        cin >> customerId;
        if (customerId == "0")
            break;

        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i]->getId() == customerId)
            {
                customer = customers[i];
                customerItems = customers[i]->getItems();
                found = true;
            }
        }
        if (!found)
            cout << "Customer not found. Please try again or exit by typing 0" << endl;
    }
    found = false;

    cout << "Enter ID of Item that you wants to be returned:" << endl;
    for (int i = 0; i < customerItems.size(); i++)
    {
        cout << customerItems[i] << endl;
    }
    while (!found)
    {
        cin >> itemId;
        if (itemId == "0")
            break;

        for (int i = 0; i < customerItems.size(); i++)
        {
            if (customerItems[i].substr(0, 9) == itemId.substr(0, 9))
            {
                found = true;
                customer->returnItem(itemId.substr(0, 9));
                for (int i = 0; i < items.size(); i++)
                {
                    if (items[i]->getId() == itemId)
                    {
                        items[i]->setStock(items[i]->getStock() + 1);
                    }
                }
            }
        }
        if (!found)
            cout << "Item not found. Please try another item or exit by typing 0." << endl;
    }

    fileHandler.writeCustomersFile(customers, customerFile);
    fileHandler.writeItemsFile(items, itemFile);
}

void rentItem()
{
    vector<Customer *> customers = fileHandler.readCustomerFile(customerFile);
    vector<Item *> items = fileHandler.readItemsFile(itemFile);
    string customerId, itemId;
    bool found = false;
    bool weekLoan = false;

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
                    weekLoan = items[i]->getLoanType() == "1-week";
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
                if (customers[i]->getcustomerType() == "Guest" && !weekLoan)
                {
                    cout << "Sorry only Regular and VIP customers can rent 2-day loans. Please try again" << endl;
                    return;
                }
                success = customers[i]->borrowItem(itemId);
                if (success)
                {
                    cout << "Item with ID " << itemId << " was borrowed." << endl;
                    found = true;
                    for (int i = 0; i < items.size(); i++)
                    {
                        if (items[i]->getId() == itemId)
                        {
                            items[i]->setStock(items[i]->getStock() - 1);
                            items[i]->setAvaliable(items[i]->getStock() > 0);
                        }
                    }
                }
                else
                {
                    cout << "Renting was unsucessful. Please try again." << endl;
                }
            }
        }
    }
    fileHandler.writeCustomersFile(customers, customerFile);
    fileHandler.writeItemsFile(items, itemFile);
}


//Main function
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
        case 5:
            returnItem();
            break;
        case 6:
            displayItem(fileHandler.readItemsFile(itemFile));
            break;
        case 7:
            displayOutOfStockItem(fileHandler.readItemsFile(itemFile));
            break;
        case 8:
            displayCustomer(fileHandler.readCustomerFile(customerFile));
            break;
        case 9:
            displayCustomerGroup(fileHandler.readCustomerFile(customerFile));
            break;
        case 10:
            cout << "Choose type:" << endl;
            cout << "1. Item" << endl;
            cout << "2. Name" << endl;
            cout << "0. Exit" << endl;
            string input;
            int choice;
            cin >> input;
            try
            {
                choice = stoi(input);
            }
            catch (const invalid_argument)
            {
                cerr << "Invalid input";
                break;
            }
            if (choice == 1)
            {
                searchItem(fileHandler.readItemsFile(itemFile));
                break;
            }
            else if (choice == 2)
            {
                searchCustomer(fileHandler.readCustomerFile(customerFile));
                break;
            }
            else if (choice == 0)
            {
                break;
            }
            else
            {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    //Commanded line must be items file first, customer file second
    // Checks if the program is executed in the correct format
    if (argc != 3)
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
    itemFile = argv[1];
    customerFile = argv[2];

    // items = fileHandler.readItemsFile();
    // displayItem(items);

    // //UI
    // items = fileHandler.readItemsFile();
    input();

    return 0;
}
