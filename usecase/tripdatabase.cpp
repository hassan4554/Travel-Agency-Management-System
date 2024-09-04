#include"tripdatabase.h"

void TripDatabase::store_Trips(string depart, string dest, double cost)
{
	ofstream outData;
	outData.open("tripdata.txt", ios_base::app);
	outData << depart + ',';
	outData << dest + ',';
	outData << cost << ':';
	outData.close();
}

void TripDatabase::load_Trips()
{
	ifstream inData("tripdata.txt");
	TripController* ptr = TripController::getInstance();
	int i = 0;

	while (inData.eof() == 0)
	{
		string departure, destination;
		double cost;
		getline(inData, departure, ',');
		getline(inData, destination, ',');
		inData >> cost;
		inData.ignore(1, ':');

		ptr->loading_Tours(departure, destination, cost, i);
		i++;
	}
	inData.close();
}