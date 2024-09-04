#include"employeeloginview.h"

void EmployeeLoginView::employeeID_in()
{
	cout << "Employee ID: ";
	cin >> id;
}

void EmployeeLoginView::password_in()
{
	cout << "Password   : ";
	cin >> password;
}

bool EmployeeLoginView::employeeLogin()
{
	EmployeeController* ptr = EmployeeController::getInstance();
	int attempts = 3;

	while (true)
	{
		employeeID_in();
		password_in();
		bool flag = ptr->check_Login(id, password);
		if (flag == true)
		{
			return true;
		}
		else
		{
			cout << "\nIncorrect Employee id OR Password!\n";
			attempts--;
			cout << attempts << " attempts left.\n\n";
			if (attempts == 0)
			{
				return false;
			}
		}
	}
	return false;
}