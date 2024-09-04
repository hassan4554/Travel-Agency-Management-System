#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include"user.h"
#include"customercontroller.h"
#include"employeecontroller.h"
#include"tripdatabase.h"


class Admin{
	string adminName;
	string adminPassword;
public:
	Admin();
	void delete_Customer();
	void delete_Employee();
	string getAdminName();
	string getAdminPassword();
	void add_Tours();
	void deleteTrip();
};

#endif // !ADMIN_H
