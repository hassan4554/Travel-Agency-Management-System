#pragma once
#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
using namespace std;

class User {
protected:
	string Password;
	string Name;
	string address;
	string email;
	string phone_number;
public:
	void set_Password(string);
	string get_Password();

	void set_Name(string);
	string get_Name();

	void set_Address(string);
	string get_Address();

	void set_Email(string);
	string get_Email();

	void set_Phone_Number(string);
	string get_Phone_Number();

	virtual void Display() = 0;
};

#endif
