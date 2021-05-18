#include "FileHandlar.h"

FileHandlar::FileHandlar() {}
FileHandlar :: ~FileHandlar() {}


bool FileHandlar::isCustomerFile() // function to check for the customer file 
{
	ifstream _fcount;
	_fcount.open("customers.txt");
	if (_fcount) // check if file can be open
	{
		cout << "Customer File Exists" << endl;
		_fcount.close();
		return true;
	}
	else // check if file can be open
	{
		cout << "Customer file doesn't exist" << endl;
		_fcount.close();
		return false;
	}
}

bool FileHandlar::writeCustomerFile(string line) // write to customer text file
{
	ofstream countFile("customer.txt");
	countFile << line;
	countFile.close();
	return true;
}


bool FileHandlar::isItemFile()
{
	ifstream _fcount;
	_fcount.open("items.txt");
	if (_fcount) // check if item text file can be open
	{
		cout << "Items File Exists" << endl;
		_fcount.close();
		return true;
	}
	else
	{
		cout << "Items file doesn't exist" << endl;
		_fcount.close();
		return false;
	}
}