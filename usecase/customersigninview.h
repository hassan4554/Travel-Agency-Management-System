#pragma once
#ifndef CUSTOMERSIGNINVIEW_H
#define CUSTOMERSIGNINVIEW_H
#include"customercontroller.h"

class CustomerSigninView {
	string userName;
	string passWord;
	string Name;
	string Address;
	string Email;
	string phn_number;
	string cnic;
	string setUsername();
	string setPassword();
	string setName();
	string setAddress();
	string setEmail();
	string setPhone();
	string setCNIC();
	bool checkUsername();
	bool checkCnic();
public:
	bool get_info();
	void createCustomer();
};
#endif