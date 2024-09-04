#pragma once
#ifndef BOOKINGCONTROLLER_H
#define BOOKINGCONTROLLER_H
#include"booking.h"
#include"bookingdatabase.h"
#include<iomanip>

class BookingController {
	int maxBookings = 10;
	int num_nonBookings = 0;
	int num_Bookings = 0;
	int bookings_Cancelled = 0;
	Booking* non_bookings = new Booking[maxBookings];
	Booking* bookings = new Booking[maxBookings];
	Booking* cancelled_Bookings = new Booking[maxBookings];
	static BookingController* instance;
	BookingController();

public:
	static BookingController* getInstance()
	{
		return instance;
	}
	void set_Num_nonBookings();
	int get_Num_nonBookings();
	void set_Num_Bookings();
	int get_Num_Bookings();
	Booking making_Booking(Trip, string, string, Hotel);
	void load_unapproved_Bookings(Trip, string, int, string, Hotel);
	void load_approved_Bookings(Trip, string, int, string, Hotel);
	Booking unapproved_Booking_Shifting(int);
	void approved_Bookings(Booking);
	void display_unapproved_Bookings();
	void display_approved_Bookings();
	void remove_unapproved_Booking(int);
	void remove_approved_Booking(int);
	void new_unapproved_Data();
	void new_approved_Data();
	int booking_Status(int);
	bool booking_Payment();
	bool show_Customers_Bookings(string);
	bool cancelling_Booking(int);
	Booking cancelled_Booking_By_Employee(int);
	void store_Cancelled_Bookings(Booking);
	void load_Cancelled_Bookings(Trip, string, int, string, Hotel);
	void invoice_Data(Booking);
};

#endif // !BOOKINGCONTROLLER_H
