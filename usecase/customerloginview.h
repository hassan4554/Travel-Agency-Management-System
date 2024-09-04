#pragma once
#ifndef CUSTOMERLOGINVIEW_H
#define CUSTOMERLOGINVIEW_H
#include"customercontroller.h"

class CustomerLoginView 
{
	string username;
	string password;

	void username_in();
	void password_in();

public:
	int customer_Login();
};

#endif // !CUSTOMERLOGINVIEW_H
