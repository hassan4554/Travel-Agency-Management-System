#include "hotelcontroller.h"

HotelController::HotelController() {}
HotelController* HotelController::instance = new HotelController();

void HotelController::loadHotels(string name)
{
	hotels[numHotels].setHotelName(name);
	numHotels++;
}

void HotelController::display_Hotels()
{
	int i = 0;
	cout << "\t\tHotels:\n\n";
	while (i < numHotels)
	{
		cout << i + 1 << ". " << hotels[i].getHotelName() << endl;
		i++;
	}
}

Hotel HotelController::choose_Hotel()
{
	int attempt = 3;
	while (true)
	{
		int choice;
		cout << "\nChoose a hotel of your choice: ";
		cin >> choice;
		choice--;

		if (choice < numHotels && choice >= 0)
		{
			return hotels[choice];
		}
		else
		{
			attempt--;
			cout << "\nWrong Input!\n";
			if (attempt == 0)
			{
				Hotel h;
				h.setHotelName("No Hotel Selected");
				return h;
			}
		}
	}
}

int HotelController::choose_Stay()
{
	int days;
	cout << "Days to stay: ";
	cin >> days;

	return days;
}