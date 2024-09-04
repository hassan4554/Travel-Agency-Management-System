#include "customersigninview.h"
#include "customerloginview.h"
#include "employeesigninview.h"
#include "customerdatabase.h"
#include "employeedatabase.h"
#include "employeeloginview.h"
#include "adminloginview.h"
#include "tripdatabase.h"
#include "bookingdatabase.h"
#include "bookingview.h"
#include "hoteldatabase.h"


void DisplayStart()
{
	cout << "\t\t\t\t";
	for (int i = 0; i < 30; i++)
	{
		cout << "* ";
	}
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "\t\t\t\t*\t\t\t\t\t\t\t  *" << endl;
		if (i == 3)
		{
			cout << "\t\t\t\t*\t\tWelcome to 'Sublime Travels' \t\t  *\n";
			cout << "\t\t\t\t*\t\t\t\t\t\t\t  *\n";
			cout << "\t\t\t\t*\t\t     Explore The World\t\t\t  *\n";
		}
	}
	cout << "\t\t\t\t";
	for (int i = 0; i < 30; i++)
	{
		cout << "* ";
	}

	cout << endl;
}
void programExit()
{
	cout << "Exiting...\n";
	exit(0);
}

class Main
{
public:
	void start()
	{

		char choose;
		int attempt = 3;

		system("cls");
		DisplayStart();

		TripDatabase tripData;
		tripData.load_Trips();

		CustomerDatabase customerData;
		customerData.load_Customer_Data();

		BookingDatabase bookingData;
		bookingData.load_unapproved_Booking_data();
		bookingData.load_approved_Bookings_Data();
		bookingData.load_Cancel_Bookings();

		EmployeeDatabase employeeData;
		employeeData.load_Employee_Data();

		HotelDatabase hotelData;
		hotelData.loading_Hotels();

		while (true)
		{

			cout << "\nChoose:\n\t1. SignIn\n\n\t2. Login\n\n\t0. Exit\n";
			cin >> choose;
			cout << endl;

			if (choose == '0')
			{
				programExit();
			}

			else if (choose == '1')
			{
				cout << "\t\t\tSIGN-IN\n1. Customer Sign-in\n\n2. Emplyee Sign-in\n";
				cin >> choose;
				cout << endl;

				if (choose == '1')
				{
					cout << "\n\t\t\tCustomer SignIn\n";

					CustomerSigninView signin;
					bool flag = signin.get_info();
					system("cls");
					DisplayStart();

					if (flag)
					{
						customer_Login_Menu();
					}
				}

				else if (choose == '2')
				{
					cout << "\n\t\t\tEmployee SignIn\n";

					EmployeeSigninView signIn;
					bool flag = signIn.get_Info();
					system("cls");
					DisplayStart();

					if (flag)
					{
						employee_Login_Menu();
					}
				}

				else
				{
					cout << "Wrong Input!\n";
				}

			}

			else if (choose == '2')
			{
				cout << "\t\t\tLOG-IN\n1. Admin Login\n\n2. Employee Login\n\n3. Customer Login\n";
				cin >> choose;
				cout << endl;

				if (choose == '1')
				{
					admin_Login_Menu();
				}

				else if (choose == '2')
				{
					employee_Login_Menu();
				}

				else if (choose == '3')
				{
					customer_Login_Menu();
				}
			}

			else
			{
				cout << "Please choose action wisely!\n";
				attempt--;
				cout << attempt << " attempts left!\n";
				if (attempt == 0)
				{
					programExit();
				}
			}
		}
	}

	void customer_Login_Menu()
	{
		char choose;
		system("cls");
		DisplayStart();
		cout << "\n\t\t\tCustomer Login\n";
		CustomerLoginView login;
		int flag = login.customer_Login();
		CustomerController* ptr = CustomerController::getInstance();

		while (flag != -1)
		{
			cout << "\nChoose:\n\t1. Make Booking\t\t2. Cancel Bookings\n\n\t3. My Bookings\t\t4. Check Booking\n\n\t\t    0. Main Menu";
			cin >> choose;

			system("cls");
			DisplayStart();
			if (choose == '1')
			{
				cout << "\n\t\tBooking Menu:\n";
				ptr->make_Booking(flag);
			}

			else if (choose == '2')
			{
				cout << "\n\t\tCancel Booking:\n";
				ptr->cancel_Booking(flag);
			}

			else if (choose == '3')
			{
				ptr->my_Bookings(flag);
			}

			else if (choose == '4')
			{
				cout << "\n\t\tCheck Status:\n";
				ptr->checkStatus();
			}

			else if (choose == '0')
			{
				flag = -1;
			}

			else
			{
				cout << "Wrong Input!\n";
				flag = -1;
			}
		}

	}

	void employee_Login_Menu()
	{
		char choose;
		system("cls");
		DisplayStart();

		cout << "\n\t\t\tEmployee Login\n";
		EmployeeLoginView login;
		bool flag = login.employeeLogin();
		EmployeeController* ptr = EmployeeController::getInstance();

		while (flag)
		{
			cout << "\nChoose:\n\t1. Confirm Booking\t\t\t2. Cancel Booking\n\n\t\t\t\t0. Main Menu";
			cin >> choose;
			if (choose == '1')
			{
				cout << "\n\t\tBooking Confirming:\n";
				ptr->approve_Bookings();
			}
			else if (choose == '2')
			{
				cout << "\n\t\tBooking Cancelling:\n";
				ptr->cancel_Booking();
			}
			else if (choose == 0)
			{
				flag = false;
			}
			else
			{
				cout << "Wrong Input!\n";
				flag = false;
			}
		}
	}

	void admin_Login_Menu()
	{
		system("cls");
		DisplayStart();

		cout << "\n\t\t\tAdmin Login\n";
		AdminLoginView login;
		Admin obj;
		bool flag = login.admin_Login();

		while (flag)
		{
			char choose;
			cout << "\nHi Admin! Nice seeing you again\nPlease choose your action.\n\n1. Delete Customer\t\t2. Delete Employe\n3. Add Trip\t\t\t4. Delete Trip\n\t\t0. Main Menu";
			cin >> choose;
			system("cls");
			DisplayStart();
			cout << endl;

			if (choose == '1')
			{
				cout << "\n\t\tCustomer Deleting:\n";
				obj.delete_Customer();
			}

			else if (choose == '2')
			{
				cout << "\n\t\tEmployee Deleting:\n";
				obj.delete_Employee();
			}

			else if (choose == '3')
			{
				cout << "\n\t\tTrip Adding:\n";
				obj.add_Tours();
			}

			else if (choose == '4')
			{
				cout << "\n\t\tTrip Deleting:\n";
				obj.deleteTrip();
			}

			else if (choose == '0')
			{
				flag = false;
			}

			else
			{
				cout << "Wrong Input\n";
				flag = false;
			}
		}
	}
};

int main()
{
	Main obj;
	obj.start();
	return 0;
}