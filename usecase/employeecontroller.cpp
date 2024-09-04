#include"employeecontroller.h"

EmployeeController::EmployeeController() {}
EmployeeController* EmployeeController::instance = new EmployeeController();

void EmployeeController::setnumEmployees()
{
	numEmployees = 0;
}

bool EmployeeController::isFull()
{
	if (numEmployees < maxEmployees)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void EmployeeController::create_Employee(string id, string pass, string name, string address, string email, string position, string no, float salary)
{
	if (!isFull())
	{
		Employee employee;
		employee.set_Employee_ID(id);
		employee.set_Password(pass);
		employee.set_Name(name);
		employee.set_Address(address);
		employee.set_Email(email);
		employee.set_Position(position);
		employee.set_Phone_Number(no);
		employee.set_Salary(salary);
		employees[numEmployees] = employee;

		EmployeeDatabase data;
		data.store_Employee_Data(id, pass, name, address, email, position, no, salary);
		data.load_Employee_Data();
		numEmployees++;
	}
	else
	{
		cout << "\nMax Employees reached!\n";
	}
}

bool EmployeeController::checking_EmployeeID(string id)
{
	int i = 0;
	while (i < numEmployees)
	{
		if (employees[i].get_Employee_ID() == id)
		{
			return true;
		}
		i++;
	}
	return false;
}

void EmployeeController::loading_Employee_Data(string id, string pass, string name, string adr, string email, string pos, string no, float salary)
{
	if (id == "")
	{
		return;
	}

	employees[numEmployees].set_Employee_ID(id);
	employees[numEmployees].set_Password(pass);
	employees[numEmployees].set_Name(name);
	employees[numEmployees].set_Address(adr);
	employees[numEmployees].set_Email(email);
	employees[numEmployees].set_Position(pos);
	employees[numEmployees].set_Phone_Number(no);
	employees[numEmployees].set_Salary(salary);
	numEmployees++;
}

bool EmployeeController::check_Login(string id, string pass)
{
	int i = 0;
	while (i < numEmployees)
	{
		if (employees[i].get_Employee_ID() == id)
		{
			if (employees[i].get_Password() == pass)
			{
				return true;
			}
		}
		i++;
	}
	return false;
}

void EmployeeController::display_Employee()
{
	int i = 0;
	while (i < numEmployees)
	{
		cout << i + 1 << ". " << endl;
		employees[i].Display();
		i++;
	}
}

void EmployeeController::new_Data()
{
	int i = 0;
	EmployeeDatabase obj;
	string id, pass, name, adr, email, no, pos;
	float salary;

	ofstream outFile("employeedata.txt", ios::out | ios::trunc);
	outFile.close();

	while (i < numEmployees)
	{
		id = employees[i].get_Employee_ID();
		pass = employees[i].get_Password();
		name = employees[i].get_Name();
		adr = employees[i].get_Address();
		email = employees[i].get_Email();
		no = employees[i].get_Phone_Number();
		salary = employees[i].get_Salary();
		pos = employees[i].get_Position();

		obj.store_Employee_Data(id, pass, name, adr, email, pos, no, salary);
		i++;
	}
}

bool EmployeeController::deletingEmployee(int index)
{

	if (index >= numEmployees)
	{
		cout << "Wrong Employee No.\nNo employee deleted\n";
		return false;
	}
	else
	{
		Employee* empArr = new Employee[maxEmployees - 1];
		for (int i = 0, j = 0; i < numEmployees; i++)
		{
			if (i != index)
			{
				empArr[j] = employees[i];
				j++;
			}
		}

		delete[] employees;
		employees = empArr;
		numEmployees--;

		return true;
	}
}

void EmployeeController::approve_Bookings()
{
	int no, attempt = 3;
	bool flag = true;
	Booking obj;

	BookingController* ptr = BookingController::getInstance();
	ptr->display_unapproved_Bookings();

	while (flag)
	{
		cout << "\nEnter the respective Booking No. to approve  OR 0 to confirm all: ";
		cin >> no;

		if (no == 0)
		{
			int index = ptr->get_Num_nonBookings();
			int i = 0;

			while (i != index)
			{
				int j = 0;
				obj = ptr->unapproved_Booking_Shifting(j);
				ptr->approved_Bookings(obj);
				i++;
			}
			flag = false;
		}

		else if (no < 0)
		{
			cout << "Invalid Input!\nno Booking Conformed\n";
		}

		else
		{
			no--;
			int index = ptr->get_Num_nonBookings();

			if (no < index)
			{
				obj = ptr->unapproved_Booking_Shifting(no);
				ptr->approved_Bookings(obj);

				flag = false;
			}

			else
			{
				cout << "Wrong Booking No.\n";
				attempt--;
				cout << attempt << " attempts left!\n";

				if (attempt == 0)
				{
					cout << "All attempts used!\n";
					flag = false;
				}
			}
		}
	}
}


void EmployeeController::cancel_Booking()
{
	int no, attempt = 3;
	bool flag = true;
	Booking obj;

	BookingController* ptr = BookingController::getInstance();
	ptr->display_unapproved_Bookings();

	while (flag)
	{
		cout << "\nEnter the respective Booking No. to cancel: ";
		cin >> no;
		no--;

		if (no < 0)
		{
			cout << "Invalid Input!\nno Booking Conformed\n";
			flag = false;
		}

		else
		{
			int index = ptr->get_Num_nonBookings();

			if (no < index)
			{
				obj = ptr->cancelled_Booking_By_Employee(no);
				ptr->store_Cancelled_Bookings(obj);

				flag = false;
			}

			else
			{
				cout << "Wrong Booking No.\n";
				attempt--;
				cout << attempt << " attempts left!\n";

				if (attempt == 0)
				{
					cout << "All attempts used!\n";
					flag = false;
				}
			}
		}
	}
}