#pragma once
#ifndef BOOKING_H
#define BOOKING_H
#include"customer.h"
#include"trip.h"
#include"Hotel.h"

class Booking
{
	int booking_ID;
	string ticket_Type;
	Trip trip;
	string cnic;
	Hotel hotel;
public:

	void set_Ticket_Type(string);
	string get_Ticket_Type();

	void setTrip(string, string, double);
	void setHotel(Hotel);

	void set_Booking_ID();
	int get_Booking_ID();
	int generate_Booking_id();
	void shift_Booking_ID(int);

	void set_Cnic(string);
	string get_Cnic();

	string get_Hotel_Name();
	int get_Hotel_Stay();

	string get_Trip_Destination();
	string get_Trip_Departure();
	double get_Trip_Cost();

};

#endif // !BOOKING_H
