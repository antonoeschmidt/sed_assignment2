
#pragma once

#include "Customers.h"
#include "Items.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class FileHandler
{
public:
	//constructor and destructor
	FileHandler();
	~FileHandler();
	bool isCustomerFile(); // check and write to customer list text file
	bool writeCustomersFile(vector<Customer *> customers, string customerFile);
	vector<Customer *> readCustomerFile(string customerFile);
	bool isItemFile(); // check if item text file exist
	vector<Item*> readItemsFile(string itemFile);
	bool writeItemsFile(vector<Item*> items, string itemFile);

private:
	// declare variable
	char *temp_array;
	string customerPrperties[7];
	string *customerItemList;
};