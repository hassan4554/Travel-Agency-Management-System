#include"customersigninview.h"
#include"customerdatabase.h"

string CustomerSigninView::setUsername()
{
	cout << "Username: ";
	cin >> userName;
	return userName;
}

string CustomerSigninView::setPassword()
{
	cout << "Password: ";
	cin >> passWord;
	return passWord;
}

string CustomerSigninView::setName()
{
	cin.ignore();
	cout << "Name    : ";
	getline(cin, Name);
	return Name;
}

string CustomerSigninView::setAddress()
{
	cin.ignore();
	cout << "Address : ";
	getline(cin, Address);
	return Address;
}

string CustomerSigninView::setEmail()
{
	cout << "Email   : ";
	cin >> Email;
	return Email;
}

string CustomerSigninView::setPhone()
{
	bool flag = true;
	int i = 0, attempt = 3, count = 0;

	while (flag)
	{
		bool checkNumber = true;
		cout << "Phone No: ";
		cin >> phn_number;

		while (phn_number[count] != '\0')
		{
			if (phn_number[count] < 48 || phn_number[count] > 57)
			{
				checkNumber = false;
				break;
			}
			count++;
		}
		if (count == 11 && checkNumber == true)
		{
			flag = false;
		}
		else
		{
			cout << "Incorrect Phone Number!\n";
			attempt--;
			if (attempt == 0)
			{
				cout << "All attempts used!\n";
				flag = false;
			}
		}
	}

	return phn_number;
}

string CustomerSigninView::setCNIC()
{
	bool flag = true;
	int i = 0, attempt = 3, count = 0;
	while (flag)
	{
		bool checkcnic = true;
		cout << "CNIC    : ";
		cin >> cnic;

		while (cnic[count] != '\0')
		{
			if (cnic[count] < 48 || cnic[count] > 57)
			{
				checkcnic = false;
				break;
			}
			count++;
		}
		if (count == 13 && checkcnic == true)
		{
			flag = false;
		}
		else
		{
			cout << "Incorrect CNIC!\n";
			attempt--;
			if (attempt == 0)
			{
				cout << "All attempts used!\n";
				flag = false;
			}
		}
	}
	return cnic;
}

bool CustomerSigninView::get_info()
{

	CustomerController* ptr = CustomerController::getInstance();
	if (!ptr->isFull())
	{
		bool isread = true, flag = true;
		int attempt = 3;

		cout << "Enter your details:\n";
		while (isread)
		{
			setUsername();
			isread = checkUsername();
			if (isread == true)
			{
				cout << "\nUsername already taken!\nPlease try another\n";
				attempt--;
				cout << attempt << " attempts left\n\n";
				if (attempt == 0)
				{
					return false;
				}
			}
		}

		if (attempt != 3)
		{
			attempt++;
		}

		setPassword();
		setName();
		while (flag)
		{
			setCNIC();
			flag = checkCnic();
			if (flag == true)
			{
				cout << "\nUsername already taken!\nPlease try another\n";
				attempt--;
				cout << attempt << " attempts left\n\n";
				if (attempt == 0)
				{
					return false;
				}
			}

		}
		setAddress();
		setEmail();
		setPhone();
		createCustomer();
		return true;
	}

	else
	{
		cout << "\nMax Customers Reached!\n";
		return false;
	}

}

void CustomerSigninView::createCustomer()
{
	CustomerController* ptr = CustomerController::getInstance();
	ptr->create_Customer(userName, passWord, Name, Address, Email, phn_number, cnic);
}

bool CustomerSigninView::checkUsername()
{
	CustomerController* ptr = CustomerController::getInstance();
	bool flag = ptr->checking_Username(userName);
	return flag;
}

bool CustomerSigninView::checkCnic()
{
	CustomerController* ptr = CustomerController::getInstance();
	bool flag = ptr->checking_Cnic(cnic);
	return flag;
}