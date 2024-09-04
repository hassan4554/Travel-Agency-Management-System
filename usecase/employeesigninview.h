#pragma once
#ifndef EMPLOYEESIGNINVIEW_H
#define EMPLOYEESIGNINVIEW_H
#include"employeecontroller.h"

class EmployeeSigninView
{
	string employeeID;
	string password;
	string name;
	string address;
	string email;
	string position;
	string phnNumber;
	float salary;
public:

	string setEmployeeID();
	string setPassword();
	string setName();
	string setAddress();
	string setEmail();
	string setPosition();
	string setPhnNumber();
	float setSalary();
	bool get_Info();
	void createEmployee();
	bool checkEmployee();
};

#endif // !EMPLOYEESIGNINVIEW_H

