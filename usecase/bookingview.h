#pragma once
#ifndef BOOKINGVIEW_H
#define BOOKINGVIEW_H
#include "bookingcontroller.h"
#include "hotelcontroller.h"

class BookingView {
	string ticketType;

public:
	string ticket_Type_in();
	void show_Trips();
	Trip choose_Trip();
	void booking_Info(string);
};

#endif // !BOOKINGVIEW_H
