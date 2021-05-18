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


bool FileHandlar::readCustomerFile() // function read customer file 
{
	int len = 0;
	string line;
	string temp;
	string collectBuff = "";

	vector<string> strBuff;
	vector<string> customerData;
	//vector<string> customerID;
	vector<string> customerItems;
	vector<string> customerItemList;
	


	int x, count, y;

	// char* temp_array;

	FileHandlar filehandlar;

	//write to customer file
	filehandlar.writeCustomerFile(1);

	if (!filehandlar.isCustomerFile()) { cout << "isCustomerFile : NO" << endl; return false; }

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
	int itr = 0;
	for (auto i = strBuff.begin(); i != strBuff.end(); ++i)
	{
		temp = *i;

		if (temp.c_str()[0] == 'C')
		{
			customerData.push_back(temp);
			if (itr != 0)
			{
				customerItems.push_back(collectBuff);
			}
			collectBuff = "";
			itr++;
		}
		if (temp.c_str()[0] == 'I')
		{
			collectBuff += temp + ',';
		}
		if (i == strBuff.end() - 2)
		{
			customerData.push_back(temp);
			customerItems.push_back(collectBuff);
			collectBuff = "";
		}

		
	}

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

bool FileHandlar::readItemFile(){
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