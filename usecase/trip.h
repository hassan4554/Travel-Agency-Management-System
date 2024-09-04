#pragma once
#ifndef TRIP_H
#define TRIP_H
#include<iostream>
#include<string>
using namespace std;

class Trip
{
	string departure;
	string destination;
	double trip_cost;

public:
	void setDeparture(string);
	string getDeparture();

	void setDestination(string);
	string getDestination();

	void setCost(double);
	double getCost();
};

#endif // !TRIP_H


