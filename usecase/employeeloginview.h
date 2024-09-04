#pragma once
#ifndef EMPLOYEELOGINVIEW_H
#define EMPLOYEELOGINVIEW_H
#include"employeecontroller.h"

class EmployeeLoginView {
	string id;
	string password;
	
	void employeeID_in();
	void password_in();

public:
	bool employeeLogin();
};

#endif // 

