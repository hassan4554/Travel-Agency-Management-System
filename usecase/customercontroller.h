#pragma once
#ifndef CUSTOMERCONTROLLER_H
#define CUSTOMERCONTROLLER_H
#include"customer.h"
#include"booking.h"
#include"customerdatabase.h"
#include"bookingview.h"
#include<fstream>

class CustomerController
{
	int numCustomers = 0;
	int maxCustomers = 20;
	static CustomerController* instance;
	CustomerController();
	Customer* customers = new Customer[maxCustomers];
public:
	static CustomerController* getInstance() {
		return instance;
	}
	void create_Customer(string, string, string, string, string, string, string);
	void setNumCustomers();
	bool checking_Username(string);
	bool checking_Cnic(string);
	void loading_data(string, string, string, string, string, string, string);
	int check_Login(string, string);
	void customers_Display();
	bool deletingCustomers(int);
	bool isFull();
	void newData();
	void make_Booking(int);
	void cancel_Booking(int);
	void my_Bookings(int);
	void checkStatus();
	void customer_Invoice(Booking);
};

#endif // !CONTROLLER_H

