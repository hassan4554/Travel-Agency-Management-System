#pragma once
#ifndef HOTEL_H
#define HOTEL_H
#include<iostream>
#include<string>
using namespace std;

class Hotel {
	string hotel_Name;
	int hotel_Stay;

public:
	Hotel();
	void setHotelName(string);
	string getHotelName();

	void setHotelStay(int);
	int getHotelStay();
};

#endif // !HOTEL_H


