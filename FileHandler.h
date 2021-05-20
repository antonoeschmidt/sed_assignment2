
#pragma once

#include "Customers.h"
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
	// check and write to customer list text file
	bool isCustomerFile();
	bool writeCustomersFile(vector<Customer*> customers);
	vector<Customer *> readCustomerFile();
	// check if item text file exist
	bool isItemFile();
	bool readItemFile();

private:
	// declare variable
	char* temp_array;
	string customerPrperties[7];
	string* customerItemList;
};