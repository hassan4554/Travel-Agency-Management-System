#include"bookingdatabase.h"

void BookingDatabase::store_unapproved_Booking_data(Booking obj)
{
	ofstream outData;
	outData.open("unapprovedbookings.txt", ios_base::app);
	outData << obj.get_Cnic() << "\n";
	outData << obj.get_Booking_ID() << "\n";
	outData << obj.get_Trip_Departure() + "\n";
	outData << obj.get_Trip_Destination() + "\n";
	outData << obj.get_Hotel_Name() + "\n";
	outData << obj.get_Hotel_Stay() << "\n";
	outData << obj.get_Trip_Cost() << "\n";
	outData << obj.get_Ticket_Type() + "\n:";

	outData.close();
	load_unapproved_Booking_data();
}

void BookingDatabase::load_unapproved_Booking_data()
{
	BookingController* ptr = BookingController::getInstance();
	ptr->set_Num_nonBookings();
	ifstream inData("unapprovedbookings.txt");

	while (!inData.eof())
	{
		Trip t;
		Hotel h;

		string tType, dest, dept, cnic, name;
		int id, days;
		double cost;

		getline(inData, cnic, '\n');;

		inData >> id;
		inData.ignore(1, '\n');

		getline(inData, dept, '\n');
		t.setDeparture(dept);

		getline(inData, dest, '\n');
		t.setDestination(dest);

		getline(inData, name, '\n');
		h.setHotelName(name);

		inData >> days;
		h.setHotelStay(days);
		inData.ignore(1, '\n');

		inData >> cost;
		t.setCost(cost);
		inData.ignore(1, '\n');

		getline(inData, tType, ':');
		size_t pos;
		while ((pos = tType.find('\n')) != (string::npos))
		{
			tType.erase(pos, 1);
		}


		if (tType != "")
		{
			ptr->load_unapproved_Bookings(t, tType, id, cnic, h);
		}

		else
		{
			break;
		}
	}

	inData.close();
}


void BookingDatabase::store_Approved_Bookings(Booking obj)
{
	ofstream outData;
	outData.open("approvedbookings.txt", ios_base::app);
	outData << obj.get_Cnic() << "\n";
	outData << obj.get_Booking_ID() << "\n";
	outData << obj.get_Trip_Departure() + "\n";
	outData << obj.get_Trip_Destination() + "\n";
	outData << obj.get_Hotel_Name() + "\n";
	outData << obj.get_Hotel_Stay() << "\n";
	outData << obj.get_Trip_Cost() << "\n";
	outData << obj.get_Ticket_Type() + "\n:";

	outData.close();
}

void BookingDatabase::load_approved_Bookings_Data()
{
	BookingController* ptr = BookingController::getInstance();
	ptr->set_Num_Bookings();
	ifstream inData("approvedbookings.txt");

	while (!inData.eof())
	{
		Trip t;
		Hotel h;
		string tType, dest, dept, cnic, name;
		int id, days;
		double cost;

		getline(inData, cnic, '\n');

		inData >> id;
		inData.ignore(1, '\n');

		getline(inData, dept, '\n');
		t.setDeparture(dept);

		getline(inData, dest, '\n');
		t.setDestination(dest);

		getline(inData, name, '\n');
		h.setHotelName(name);

		inData >> days;
		h.setHotelStay(days);
		inData.ignore(1, '\n');

		inData >> cost;
		t.setCost(cost);
		inData.ignore(1, '\n');

		getline(inData, tType, ':');
		size_t pos;
		while ((pos = tType.find('\n')) != (string::npos))
		{
			tType.erase(pos, 1);
		}

		if (tType != "")
		{
			ptr->load_approved_Bookings(t, tType, id, cnic, h);
		}

		else
		{
			break;
		}
	}
	inData.close();
}

void BookingDatabase::store_Cancel_Bookings(Booking obj)
{
	ofstream outData;
	outData.open("cancelledBookings.txt", ios_base::app);
	outData << obj.get_Cnic() << "\n";
	outData << obj.get_Booking_ID() << "\n";
	outData << obj.get_Trip_Departure() + "\n";
	outData << obj.get_Trip_Destination() + "\n";
	outData << obj.get_Hotel_Name() + "\n";
	outData << obj.get_Hotel_Stay() << "\n";
	outData << obj.get_Trip_Cost() << "\n";
	outData << obj.get_Ticket_Type() + "\n:";

	outData.close();
}

void BookingDatabase::load_Cancel_Bookings()
{
	BookingController* ptr = BookingController::getInstance();
	ifstream inData("cancelledBookings.txt");

	while (!inData.eof())
	{
		Trip t;
		Hotel h;
		string tType, dest, dept, cnic, name;
		int id, days;
		double cost;

		getline(inData, cnic, '\n');

		inData >> id;
		inData.ignore(1, '\n');

		getline(inData, dept, '\n');
		t.setDeparture(dept);

		getline(inData, dest, '\n');
		t.setDestination(dest);

		getline(inData, name, '\n');
		h.setHotelName(name);

		inData >> days;
		h.setHotelStay(days);
		inData.ignore(1, '\n');

		inData >> cost;
		t.setCost(cost);
		inData.ignore(1, '\n');

		getline(inData, tType, ':');
		size_t pos;
		while ((pos = tType.find('\n')) != (string::npos))
		{
			tType.erase(pos, 1);
		}

		if (tType != "")
		{
			ptr->load_Cancelled_Bookings(t, tType, id, cnic, h);
		}

		else
		{
			break;
		}
	}
	inData.close();
}