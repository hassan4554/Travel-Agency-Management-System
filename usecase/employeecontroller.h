#pragma once
#ifndef EMPLOYEECONTROLLER_H
#define EMPLOYEECONTROLLER_H
#include"employee.h"
#include"employeedatabase.h"
#include"bookingdatabase.h"

class EmployeeController 
{
	int maxEmployees=10;
	int numEmployees = 0;
	Employee* employees=new Employee[maxEmployees];
	static EmployeeController* instance;
	EmployeeController();
public:
	void create_Employee(string, string, string, string, string, string, string, float);
	static EmployeeController* getInstance() {
		return instance;
	}
	void setnumEmployees();
	bool checking_EmployeeID(string);
	void loading_Employee_Data(string, string, string, string, string, string, string,float);
	bool check_Login(string, string);
	void display_Employee();
	void new_Data();
	bool isFull();
	bool deletingEmployee(int);
	void approve_Bookings();
	void cancel_Booking();
};

#endif // !EMPLOYEECONTROLLER_H

