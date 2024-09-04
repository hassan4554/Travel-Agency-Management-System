#include "hoteldatabase.h"

void HotelDatabase::loading_Hotels()
{
	ifstream inData("hoteldata.txt");
	HotelController* ptr = HotelController::getInstance();

	while (inData.eof() == 0)
	{
		string name;
		getline(inData, name, '\n');
		ptr->loadHotels(name);
	}

}