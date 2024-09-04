#include"tripcontroller.h"
#include"tripdatabase.h"

TripController::TripController() {}

TripController* TripController::instance = new TripController();

void TripController::adding_Tour(string dep, string dest, double cost)
{
	TripDatabase obj;
	obj.store_Trips(dep, dest, cost);
}

void TripController::loading_Tours(string dep, string dest, double cost, int index)
{
	if (dep == "" || dest == "")
	{
		return;
	}
	trips[index].setDeparture(dep);
	trips[index].setDestination(dest);
	trips[index].setCost(cost);
	numTrips = index + 1;

}

void TripController::display_Trips()
{
	int i = 0;
	while (i < numTrips)
	{
		cout << i + 1 << ".\n";
		cout << "Departure:   " << trips[i].getDeparture() << endl;
		cout << "Destination: " << trips[i].getDestination() << endl;
		cout << "Cost:        " << trips[i].getCost() << endl << endl;
		i++;
	}
}

bool TripController::deleting_Trip(int index)
{
	if (index >= numTrips)
	{
		cout << "Wrong Trip No.\nNo Trip deleted\n";
		return false;
	}

	else
	{
		Trip* newArr = new Trip[maxTrips - 1];
		for (int i = 0, j = 0; i < numTrips; i++)
		{
			if (i != index)
			{
				newArr[j] = trips[i];
				j++;
			}
		}

		delete[] trips;
		trips = newArr;
		numTrips--;

		return true;
	}
}

void TripController::new_Data()
{
	int i = 0;
	TripDatabase obj;
	string dep, dest;
	double cost;

	ofstream outFile("tripdata.txt", ios::out | ios::trunc);
	outFile.close();

	while (i<numTrips)
	{
		dep = trips[i].getDeparture();
		dest = trips[i].getDestination();
		cost = trips[i].getCost();

		obj.store_Trips(dep, dest, cost);
		i++;
	}
}

Trip TripController::choosing_trip(int index)
{
	Trip obj;
	obj.setDeparture(trips[index].getDeparture());
	obj.setDestination(trips[index].getDestination());
	obj.setCost(trips[index].getCost());
	return obj;

}

int TripController::get_numTrips()
{
	return numTrips;
}