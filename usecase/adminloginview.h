#pragma once
#ifndef ADMINLOGINVIEW_H
#define ADMINLOGINVIEW_H
#include"admin.h"

class AdminLoginView
{
	string username;
	string pass;

public:
	string username_in();
	string password_in();
	bool admin_Login();
};

#endif // !ADMINLOGINVIEW_H

