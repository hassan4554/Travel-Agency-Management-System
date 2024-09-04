#include "customercontroller.h"

CustomerController* CustomerController::instance = new CustomerController();
CustomerController::CustomerController() {}

void CustomerController::setNumCustomers()
{
	numCustomers = 0;
}

bool CustomerController::isFull()
{
	if (numCustomers < maxCustomers)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void CustomerController::create_Customer(string username, string password, string name, string adr, string email, string no, string Cnic)
{
	if (!isFull())
	{
		Customer customer;
		customer.set_Username(username);
		customer.set_Password(password);
		customer.set_Name(name);
		customer.set_Address(adr);
		customer.set_Email(email);
		customer.set_Phone_Number(no);
		customer.set_CNIC(Cnic);
		customers[numCustomers] = customer;
		numCustomers++;
		CustomerDatabase customer_Data;
		customer_Data.store_Customer_Data(username, password, name, adr, email, no, Cnic);
	}

	else {
		cout << "\nMax limit reached!\n";
	}
}

void CustomerController::loading_data(string username, string pass, string name, string adr, string email, string no, string Cnic)
{
	if (username == "")
	{
		return;
	}
	customers[numCustomers].set_Username(username);
	customers[numCustomers].set_Password(pass);
	customers[numCustomers].set_Name(name);
	customers[numCustomers].set_Address(adr);
	customers[numCustomers].set_Email(email);
	customers[numCustomers].set_Phone_Number(no);
	customers[numCustomers].set_CNIC(Cnic);
	numCustomers++;
}

bool CustomerController::checking_Username(string name)
{
	int i = 0;
	while (i < numCustomers)
	{
		if (customers[i].get_Username() == name)
		{
			return true;
		}
		i++;
	}
	return false;
}

bool CustomerController::checking_Cnic(string cnic)
{
	int i = 0;
	while (i < numCustomers)
	{
		if (customers[i].get_CNIC() == cnic)
		{
			return true;
		}
		i++;
	}
	return false;
}

int CustomerController::check_Login(string name, string pass)
{
	int i = 0;
	while (i < numCustomers)
	{
		if (customers[i].get_Username() == name)
		{
			if (customers[i].get_Password() == pass)
			{
				return i;
			}
		}
		i++;
	}
	return -1;
}

void CustomerController::customers_Display()
{
	int i = 0;
	while (i < numCustomers)
	{
		cout << i + 1 << ". " << endl;
		customers[i].Display();
		i++;
	}
}

bool CustomerController::deletingCustomers(int index)
{
	if (index >= numCustomers)
	{
		cout << "Wrong Customer No.\nNo customer deleted\n";
		return false;
	}
	else
	{
		Customer* Arr = new Customer[maxCustomers];
		for (int i = 0, j = 0; i < numCustomers; i++)
		{
			if (i != index)
			{
				Arr[j] = customers[i];
				j++;
			}
		}

		delete[] customers;
		customers = Arr;
		numCustomers--;

		return true;
	}
}

void CustomerController::newData()
{
	int i = 0;
	string Uname, pass, name, adr, email, no, cnic;

	ofstream outFile("customerdata.txt", ios::out | ios::trunc);
	outFile.close();

	while (i < numCustomers)
	{
		Uname = customers[i].get_Username();
		pass = customers[i].get_Password();
		name = customers[i].get_Name();
		adr = customers[i].get_Address();
		email = customers[i].get_Email();
		no = customers[i].get_Phone_Number();
		cnic = customers[i].get_CNIC();

		CustomerDatabase customer_Data;
		customer_Data.store_Customer_Data(Uname, pass, name, adr, email, no, cnic);
		i++;
	}
}

void CustomerController::make_Booking(int index)
{
	BookingView book;
	book.booking_Info(customers[index].get_CNIC());
}

void CustomerController::checkStatus()
{
	int id;
	cout << "Enter Booking ID: ";
	cin >> id;
	BookingController* ptr = BookingController::getInstance();
	int flag = ptr->booking_Status(id);

	if (flag == 1)
	{
		cout << "\nBooking confirmed!\n";
	}

	else if (flag == 2)
	{
		cout << "\nBooking not confirmed\n";
	}

	else if (flag == 3)
	{
		cout << "\nBooking Cancelled by Employee\n";
	}
	else
	{
		cout << "\nBooking does not exist!\n";
	}
}

void CustomerController::my_Bookings(int index)
{	
	BookingController* ptr = BookingController::getInstance();
	bool flag = ptr->show_Customers_Bookings(customers[index].get_CNIC());

	if (!flag)
	{
		cout << "\nYou have made no Booking!\n";
	}
}

void CustomerController::cancel_Booking(int index)
{
	BookingController* ptr = BookingController::getInstance();

	bool flag = ptr->show_Customers_Bookings(customers[index].get_CNIC());

	if (!flag)
	{
		cout << "\nYou have made no Booking!\n";
	}

	else
	{
		int id;
		cout << "Enter Booking ID: ";
		cin >> id;

		bool isread = ptr->cancelling_Booking(id);

		if (isread)
		{
			cout << "\nBooking cancelled!\n";
		}
		else
		{
			cout << "\nBooking does not exist!\n";
		}
	}
}

void CustomerController::customer_Invoice(Booking obj)
{
	BookingController* ptr = BookingController::getInstance();

	cout << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "//";
	}
	cout << "\n\t\t\tCOSTUMER INVOICE\n";
	for (int i = 0; i < 30; i++)
	{
		cout << "//";
	}
	ptr->invoice_Data(obj);
	for (int i = 0; i < 30; i++)
	{
		cout << "//";
	}
	cout << "\n\t\t\tThank You!\n";
	for (int i = 0; i < 30; i++)
	{
		cout << "//";
	}
	cout << endl;
}