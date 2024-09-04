#include"trip.h"


void Trip::setDeparture(string dep)
{
	departure = dep;
}

string Trip::getDeparture()
{
	return departure;
}

void Trip::setDestination(string dest)
{
	destination = dest;
}

string Trip::getDestination()
{
	return destination;
}

void Trip::setCost(double cost)
{
	trip_cost = cost;
}

double Trip::getCost()
{
	return trip_cost;
}
