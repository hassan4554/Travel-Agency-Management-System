#include"booking.h"
#include<cstdlib>
#include<ctime>

void Booking::set_Ticket_Type(string Ttype)
{
	ticket_Type = Ttype;
}

string Booking::get_Ticket_Type()
{
	return ticket_Type;
}

void Booking::setTrip(string dept, string dest, double cost)
{
	trip.setDeparture(dept);
	trip.setDestination(dest);
	trip.setCost(cost);
}

int Booking::generate_Booking_id()
{
	srand(time(0));
	int id = 0;
	for (int i = 0; i < 6; i++)
	{
		int z = (rand() % 10);
		id += z;
		id *= 10;
	}
	return id;
}

void Booking::set_Booking_ID()
{
	booking_ID = generate_Booking_id();
}

int Booking::get_Booking_ID()
{
	return booking_ID;
}

string Booking::get_Trip_Departure()
{
	return trip.getDeparture();
}

string Booking::get_Trip_Destination()
{
	return trip.getDestination();
}

double Booking::get_Trip_Cost()
{
	return trip.getCost();
}

void Booking::shift_Booking_ID(int id)
{
	booking_ID = id;
}

void Booking::set_Cnic(string CNIC)
{
	cnic = CNIC;
}

string Booking::get_Cnic()
{
	return cnic;
}

void Booking::setHotel(Hotel h)
{
	hotel.setHotelName(h.getHotelName());
	hotel.setHotelStay(h.getHotelStay());
}

string Booking::get_Hotel_Name()
{
	return hotel.getHotelName();
}

int Booking::get_Hotel_Stay()
{
	return hotel.getHotelStay();
}
