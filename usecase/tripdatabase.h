#pragma once
#ifndef TRIPDATABASE_H
#define TRIPDATABASE_H
#include"tripcontroller.h"
#include<fstream>

class TripDatabase
{
public:
	void store_Trips(string, string, double);
	void load_Trips();
};
#endif // !TRIPDATABASE_H