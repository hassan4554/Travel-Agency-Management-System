#pragma once
#ifndef HOTELCONTROLLER_H
#define HOTELCONTROLLER_H
#include "Hotel.h"

class HotelController {
	int maxHotels = 10;
	int numHotels = 0;
	Hotel* hotels = new Hotel[maxHotels];
	static HotelController* instance;
	HotelController();
public:
	static HotelController* getInstance()
	{
		return instance;
	}
	void loadHotels(string);
	void display_Hotels();
	Hotel choose_Hotel();
	int choose_Stay();
};
#endif // !HOTELCONTROLLER_H