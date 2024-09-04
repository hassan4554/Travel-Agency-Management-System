#include"customerdatabase.h"
#include"customercontroller.h"

void CustomerDatabase::store_Customer_Data(string username, string password, string name, string adr, string email, string no, string Cnic)
{
	ofstream outData;
	outData.open("customerdata.txt", ios_base::app);
	if (outData.is_open())
	{
		outData << username + "\n" + password + "\n";
		outData << name + "\n";
		outData << adr + "\n";
		outData << email + "\n";
		outData << no << "\n";
		outData << Cnic << "\n:\n";
		outData.close();
	}
	else
	{
		cout << "Unable to open file.";
	}
}

void CustomerDatabase::load_Customer_Data()
{
	CustomerController* ptr = CustomerController::getInstance();
	ifstream inData("customerdata.txt");
	ptr->setNumCustomers();

	while (inData.eof() == 0)
	{
		string username, pass, name, address, email, No, CNIC;

		getline(inData, username, '\n');
		
		getline(inData, pass, '\n');
		
		getline(inData, name, '\n');
		
		getline(inData, address, '\n');
		
		getline(inData, email, '\n');
		
		getline(inData, No, '\n');
		
		getline(inData, CNIC, ':');
		size_t pos = 0;
		while ((pos = CNIC.find('\n')) != (string::npos))
		{
			CNIC.erase(pos, 1);
		}
		inData.ignore(1, '\n');
		ptr->loading_data(username, pass, name, address, email, No, CNIC);
	}
	inData.close();
}
