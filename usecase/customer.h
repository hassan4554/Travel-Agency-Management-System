#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"user.h"

class Customer :public User{
	string Username;
	string CNIC;
public:
	void set_Username(string);
	string get_Username();

	void set_CNIC(string);
	string get_CNIC();

	void Display() override;
};
#endif // !CUSTOMER_H
