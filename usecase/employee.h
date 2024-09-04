#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include"user.h"

class Employee:public User{
	string employee_ID;
	string Position;
	float Salary;

public:
	void set_Employee_ID(string);
	string get_Employee_ID();

	void set_Position(string);
	string get_Position();

	void set_Salary(float);
	float get_Salary();

	void Display() override;
};

#endif
