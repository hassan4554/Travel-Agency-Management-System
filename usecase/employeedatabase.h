#pragma once
#ifndef EMPLOYEEDATABASE_H
#define EMPLOYEEDATABASE_H
#include"employee.h"
#include<fstream>

class EmployeeDatabase
{
public:
	void store_Employee_Data(string, string, string, string, string, string, string, float);
	void load_Employee_Data();
};

#endif // !EMPLOYEEDATABASE_H

