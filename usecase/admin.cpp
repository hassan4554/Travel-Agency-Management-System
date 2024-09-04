#include"admin.h"

Admin::Admin()
{
	adminName = "Hassan";
	adminPassword = "Hassan";
}

void Admin::delete_Customer()
{
	int no;
	CustomerController* ptr = CustomerController::getInstance();
	ptr->customers_Display();
	cout << "\nEnter the respective Customer No. to delete: ";
	cin >> no;
	if (no < 0)
	{
		cout << "\nInvalid Input!\n";
	}

	else
	{
		no--;
		bool flag = ptr->deletingCustomers(no);
		if (flag == true)
		{
			cout << "\nCustomer Deleted!\n";
			ptr->newData();
		}
	}
}

void Admin::delete_Employee()
{
	int no;
	EmployeeController* ptr = EmployeeController::getInstance();
	ptr->display_Employee();
	cout << "\nEnter the respective Employee No. to delete: ";
	cin >> no;

	if (no < 0)
	{
		cout << "\nInvalid Input!\n";
	}

	else
	{
		no--;
		bool flag = ptr->deletingEmployee(no);
		if (flag == true)
		{
			cout << "\nEmployee Deleted!\n";
			ptr->new_Data();
		}
	}
}

string Admin::getAdminName()
{
	return adminName;
}

string Admin::getAdminPassword()
{
	return adminPassword;
}

void Admin::add_Tours()
{
	TripController* ptr = TripController::getInstance();
	TripDatabase obj;

	string dep, des;
	double cost;
	cin.ignore();
	cout << "Departure: ";
	getline(cin, dep);
	cout << "Destination: ";
	getline(cin, des);
	cout << "Cost: ";
	cin >> cost;

	ptr->adding_Tour(dep, des, cost);
	cout << "Trip Added!\n";
	obj.load_Trips();

}

void Admin::deleteTrip()
{
	int no;
	TripController* ptr = TripController::getInstance();
	ptr->display_Trips();
	cout << "Enter the respective Trip No. to delete: ";
	cin >> no;
	if (no < 0)
	{
		cout << "\nInvalid Input!\n";
	}
	else
	{
		no--;
		bool flag = ptr->deleting_Trip(no);

		if (flag == true)
		{
			cout << "Trip Deleted!\n";
			ptr->new_Data();
		}
	}
}