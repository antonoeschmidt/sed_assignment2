
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
	bool writeCustomersFile(vector<Customer *> customers);
	vector<Customer *> readCustomerFile();
	bool isItemFile(); // check if item text file exist
	vector<Item*> readItemsFile();
	bool writeItemsFile(vector<Item*> items);

private:
	// declare variable
	char *temp_array;
	string customerPrperties[7];
	string *customerItemList;
};