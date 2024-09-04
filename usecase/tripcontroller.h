#pragma once
#ifndef TRIPCONTROLLER_H
#define TRIPCONTROLLER_H
#include"trip.h"

class TripController {
	int maxTrips = 10;
	int numTrips = 0;
	static TripController* instance;
	Trip* trips = new Trip[maxTrips];
	TripController();

public:
	static TripController* getInstance()
	{
		return instance;
	}

	void adding_Tour(string, string, double);
	void loading_Tours(string, string, double, int);
	void display_Trips();
	bool deleting_Trip(int);
	void new_Data();
	Trip choosing_trip(int);
	int get_numTrips();
};
#endif // !TRIPCONTROLLER_H