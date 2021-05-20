#include "FileHandler.h"
#include "Customers.h"
#include <sstream>
#include <string>

FileHandler::FileHandler() {}
FileHandler ::~FileHandler() {}

bool FileHandler::isCustomerFile() // function to check for the customer file
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

bool FileHandler::writeCustomersFile(vector<Customer *> customers) // write to customers text file
{
	ofstream f;
	f.open("customers.txt");

	for (int i = 0; i < customers.size(); i++)
	{
		string line = customers[i]->toText();
		f << line << endl;

		vector<string> items = customers[i]->getItems();
		if (items.size() > 0)
		{
			for (int j = 0; j < items.size(); j++)
			{
				f << items[j] << endl;
			}
		}
	}
	f.close();
	return true;
}

vector<Customer *> FileHandler::readCustomerFile() // function read customer file
{
	int len = 0;
	string line;
	string temp;
	string collectBuff = "";
	vector<string> strBuff;
	vector<Customer *> customers;
	FileHandler FileHandler;

	//write to customer file
	//FileHandler.writeCustomerFile();

	if (!FileHandler.isCustomerFile())
	{
		cout << "isCustomerFile : NO" << endl;
		return customers;
	}

	ifstream _fcount; //input customers text file

	_fcount.open("customers.txt");

	while (_fcount)
	{
		getline(_fcount, line); // if file is open get and store value in line
		if (line == "-1")
		{
			cout << "can't open file" << endl;
			break; // if file is not found
		}
		strBuff.push_back(line);
		line = "";
	}
	_fcount.close();

	for (int i = 0; i < strBuff.size(); i++)
	{
		// maybe its possible to use number of rentals in order to take the next items
		if (strBuff[i][0] == 'I')
		{
			int cusLen = customers.size();
			customers[cusLen - 1]->populateBorrowedItems(strBuff[i]);
		}

		if (strBuff[i][0] == 'C')
		{
			stringstream ss(strBuff[i]);
			vector<string> customerVector;
			while (ss.good())
			{
				string substr;
				getline(ss, substr, ',');
				customerVector.push_back(substr);
			}

			int subStrLength = customerVector[5].length() - 1; //This handles unwanted whitespace in Type of Customer

			if (customerVector[5].substr(0, subStrLength) == "Guest")
			{
				Guest *guest = new Guest(customerVector[0], customerVector[1], customerVector[2], customerVector[3]);
				customers.push_back(guest);
			}
			else if (customerVector[5].substr(0, subStrLength) == "Regular")
			{
				Regular *regular = new Regular(customerVector[0], customerVector[1], customerVector[2], customerVector[3]);
				customers.push_back(regular);
			}
			else if (customerVector[5].substr(0, subStrLength) == "VIP")
			{
				VIP *vip = new VIP(customerVector[0], customerVector[1], customerVector[2], customerVector[3]);
				customers.push_back(vip);
			}
		}
	}
	return customers;
}

bool FileHandler::isItemFile()
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

bool FileHandler::readItemFile()
{
	int count = 0;
	string sCount;
	ifstream _fcount;
	_fcount.open("items.txt");
	while (_fcount) // check if file can be open
	{
		getline(_fcount, sCount); // get line from text file and store  variable
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