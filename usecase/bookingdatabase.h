#pragma once
#ifndef BOOKINGDATABASE_H
#define BOOKINGDATABASE_H
#include"bookingcontroller.h"
#include<fstream>
using namespace std;

class BookingDatabase {

public:
	//void store_unapproved_Booking_data(Trip, string, int, string, Hotel);
	void store_unapproved_Booking_data(Booking);
	void load_unapproved_Booking_data();
	void store_Approved_Bookings(Booking);
	void load_approved_Bookings_Data();
	void store_Cancel_Bookings(Booking);
	void load_Cancel_Bookings();
};
#endif // !BOOKINGDATABASE_H
