#include"adminloginview.h"

string AdminLoginView::username_in()
{
	cout << "Name: ";
	cin >> username;
	return username;
}

string AdminLoginView::password_in()
{
	cout << "Password: ";
	cin >> pass;
	return pass;
}

bool AdminLoginView::admin_Login()
{
	int attempts = 3;

	while (true)
	{
		string Name = username_in();
		string Pass = password_in();
		Admin obj;

		if (Name == obj.getAdminName() && Pass == obj.getAdminPassword())
		{
			return true;
		}
		else
		{
			cout << "\nIncorrect Information!\n";
			attempts--;
			cout << attempts << " attempts left.\n";
			if (attempts == 0)
			{
				return false;
			}
		}
	}
	return false;
}