#include"customerloginview.h"
#include"customerdatabase.h"


void CustomerLoginView::username_in()
{
	cout << "Username: ";
	cin >> username;
}

void CustomerLoginView::password_in()
{
	cout << "Password: ";
	cin >> password;
}

int CustomerLoginView::customer_Login()
{
	CustomerController* ptr = CustomerController::getInstance();
	int attempts = 3;

	while (true)
	{
		username_in();
		password_in();
		int index = ptr->check_Login(username, password);
		if (index != -1)
		{
			return index;
		}
		else
		{
			cout << "\nIncorrect Username OR Password!\n";
			attempts--;
			cout << attempts << " attempts left.\n\n";
			if (attempts == 0)
			{
				return -1;
			}
		}
	}
	return -1;
}