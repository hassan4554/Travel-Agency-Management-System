#include"employee.h"


void Employee::set_Employee_ID(string id)
{
	employee_ID = id;
}

string Employee::get_Employee_ID()
{
	return employee_ID;
}

void Employee::set_Position(string pos)
{
	Position = pos;
}

string Employee::get_Position()
{
	return Position;
}

void Employee::set_Salary(float salary)
{
	Salary = salary;
}

float Employee::get_Salary()
{
	return Salary;
}

void Employee::Display()
{
	cout << "Name: " << get_Name() << endl;
	cout << "Employee ID: " << get_Employee_ID() << endl;
	cout << "Position: " << get_Position() << endl;
	cout << "Email: " << get_Email() << endl;
	cout << "Phone Number: " << get_Phone_Number() << endl;
	cout << "Address: " << get_Address() << endl;
}