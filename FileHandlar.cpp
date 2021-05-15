#include "FileHandlar.h"

FileHandlar::FileHandlar() {}
FileHandlar :: ~FileHandlar() {}

bool FileHandlar::isCountFile()
{
	ifstream _fcount; // using input stream to read an external text file
	_fcount.open("count.txt");
	if (_fcount) // check if file is read or exist
	{
		cout << "File Exists" << endl;
		_fcount.close();
		return true;
	}
	else // check if file is read or exist
	{
		cout << "file doesn't exist" << endl;
		return false;
	}
}

bool FileHandlar::writeCountFile(int count)  // write to the same text file
{
	ofstream countFile("count.txt");
	countFile << count;
	countFile.close();
	return true;
}

int FileHandlar::readCountFile()
{
	int count = 0;
	string sCount;
	ifstream _fcount; // input and read text file
	_fcount.open("count.txt");
	while (_fcount) // check if file can be open
	{
		getline(_fcount, sCount); // get line from text file and store in scount variable
		if (sCount == "-1")
		{
			cout << "cant open count file" << endl;
			break;
		}
		count = stoi(sCount);  // set and return count value
	}
	_fcount.close();
	return count;
}


bool FileHandlar::isCustCountFile() // similar to above function to read and count number of customers
{
	ifstream _fcount;
	_fcount.open("custCount.txt");
	if (_fcount) // check if file can be open
	{
		cout << "CustCount File Exists" << endl;
		_fcount.close();
		return true;
	}
	else // check if file can be open
	{
		cout << "CustCount file doesn't exist" << endl;
		return false;
	}
}

bool FileHandlar::writeCustCountFile(int count) // write to customer count file
{
	ofstream countFile("custCount.txt");
	countFile << count;
	countFile.close();
	return true;
}

int FileHandlar::readCustCountFile()
{
	int count = 0;
	string sCount;
	ifstream _fcount;
	_fcount.open("custCount.txt");
	while (_fcount) // check if file can be open
	{
		getline(_fcount, sCount); // get line from text file and store in scount variable
		if (sCount == "-1")
		{
			cout << "cant open custCount count file" << endl;
			break;
		}
		count = stoi(sCount); // set and return count value
	}
	_fcount.close();
	return count;
}

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