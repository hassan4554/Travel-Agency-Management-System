#include "Hotel.h"

Hotel::Hotel()
{
	hotel_Stay = 0;
}

void Hotel::setHotelName(string name)
{
	hotel_Name = name;
}

string Hotel::getHotelName()
{
	return hotel_Name;
}

void Hotel::setHotelStay(int days)
{
	hotel_Stay = days;
}

int Hotel::getHotelStay()
{
	return hotel_Stay;
}