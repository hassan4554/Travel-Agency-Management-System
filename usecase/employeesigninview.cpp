#include"employeesigninview.h"

string EmployeeSigninView::setEmployeeID()
{
	cout << "Employee ID: ";
	cin >> employeeID;
	return employeeID;
}

string EmployeeSigninView::setPassword()
{
	cout << "Password   : ";
	cin >> password;
	return password;
}

string EmployeeSigninView::setEmail()
{
	cout << "Email      : ";
	cin >> email;
	return email;
}

string EmployeeSigninView::setAddress()
{
	cout << "Address    : ";
	getline(cin, address);
	return address;
}

string EmployeeSigninView::setName()
{
	cin.ignore();
	cout << "Name       : ";
	getline(cin, name);
	return name;
}

string EmployeeSigninView::setPosition()
{
	cin.ignore();
	cout << "Position   : ";
	getline(cin, position);
	return position;
}

string EmployeeSigninView::setPhnNumber()
{
	bool flag = true;
	int i = 0, attempt = 3, count = 0;

	while (flag)
	{
		bool checkNumber = true;
		cout << "Phone No   : ";
		cin >> phnNumber;

		while (phnNumber[count] != '\0')
		{
			if (phnNumber[count] < 48 || phnNumber[count] > 57)
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

	
	return phnNumber;
}

float EmployeeSigninView::setSalary()
{
	cout << "Salary     : ";
	cin >> salary;
	return salary;
}

bool EmployeeSigninView::get_Info()
{
	EmployeeController* ptr = EmployeeController::getInstance();
	if (!ptr->isFull())
	{
		bool isread = true;
		int attempt = 3;

		cout << "Enter your details:\n";
		while (isread)
		{
			setEmployeeID();
			isread = checkEmployee();
			if (isread == true)
			{
				cout << "\nID already in use!\nPlease try another\n";
				attempt--;
				cout << attempt << " attempts left\n\n";
				if (attempt == 0)
				{
					return false;
				}
			}
		}
		setPassword();
		setName();
		setAddress();
		setEmail();
		setPosition();
		setPhnNumber();
		setSalary();
		createEmployee();
		return true;
	}

	else
	{
		cout << "\nMax Employees reached!\n";
		return false;
	}

}

void EmployeeSigninView::createEmployee()
{
	EmployeeController* ptr = EmployeeController::getInstance();
	ptr->create_Employee(employeeID, password, name, address, email, position, phnNumber, salary);
}

bool EmployeeSigninView::checkEmployee()
{
	EmployeeController* ptr = EmployeeController::getInstance();
	bool flag = ptr->checking_EmployeeID(employeeID);
	return flag;
}