#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "pch.h"
#include <typeinfo>
#include "Operations.h"
#include "Member.h"

using namespace std;

class FileHandlar // handlar class
{
public:
	//constructor and destructor
	FileHandlar();
	~FileHandlar();

	bool isCountFile(); // read and write a text file function
	bool writeCountFile(int count);
	int readCountFile(); // read, write and delete count text file
	bool deleteCountFile();

	// check, read, write and delete customer count file
	bool isCustCountFile();
	bool writeCustCountFile(int count);
	int readCustCountFile();
	bool deleteCustCountFile();

	// check and write to customer list text file
	bool isCustomerFile();
	bool writeCustomerFile(string line);
	//bool readCustomerFile(Operations* operation);

	// check if item text file exist
	bool isItemFile();

	// bool decompseCustomerData(Operations* operation, string id, string name, string address, string phone, string numRent, string rating);

private:
	// declare variable
	char* temp_array;
	string customerPrperties[7];
	string* customerItemList;
};