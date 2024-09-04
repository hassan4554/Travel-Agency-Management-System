#include"bookingcontroller.h"

BookingController::BookingController() {}
BookingController* BookingController::instance = new BookingController();

void BookingController::set_Num_nonBookings()
{
	num_nonBookings = 0;
}

int BookingController::get_Num_nonBookings()
{
	return num_nonBookings;
}

void BookingController::set_Num_Bookings()
{
	num_Bookings = 0;
}

int BookingController::get_Num_Bookings()
{
	return num_Bookings;
}

Booking BookingController::making_Booking(Trip t, string tType, string CNIC, Hotel h)
{
	Booking obj;
	string dept = t.getDeparture();
	string dest = t.getDestination();
	double cost = t.getCost();

	obj.setHotel(h);
	obj.set_Booking_ID();
	obj.set_Ticket_Type(tType);
	obj.set_Cnic(CNIC);
	obj.setTrip(dept, dest, cost);

	BookingDatabase data;
	data.store_unapproved_Booking_data(obj);

	return obj;
}

void BookingController::load_unapproved_Bookings(Trip t, string tType, int id, string cnic, Hotel h)
{
	string dept = t.getDeparture();
	string dest = t.getDestination();
	double cost = t.getCost();

	non_bookings[num_nonBookings].set_Cnic(cnic);
	non_bookings[num_nonBookings].set_Ticket_Type(tType);
	non_bookings[num_nonBookings].setTrip(dept, dest, cost);
	non_bookings[num_nonBookings].shift_Booking_ID(id);
	non_bookings[num_nonBookings].setHotel(h);
	num_nonBookings++;
}

void BookingController::display_unapproved_Bookings()
{
	int i = 0;
	cout << "\nUnapproved Bookings Data:\n";
	while (i < num_nonBookings)
	{
		cout << i + 1 << ".\n";
		cout << "Booker's CNIC: " << non_bookings[i].get_Cnic() << endl;
		cout << "Booking ID   : " << non_bookings[i].get_Booking_ID() << endl;
		cout << "Ticket Type  : " << non_bookings[i].get_Ticket_Type() << endl;
		cout << "Departure    : " << non_bookings[i].get_Trip_Departure() << endl;
		cout << "Destination  : " << non_bookings[i].get_Trip_Destination() << endl;
		cout << "Hotel Name   : " << non_bookings[i].get_Hotel_Name() << endl;
		cout << "Hotel Stay   : " << non_bookings[i].get_Hotel_Stay() << endl;
		cout << "Trip Cost    : " << non_bookings[i].get_Trip_Cost() << endl << endl;
		i++;
	}
}

void BookingController::display_approved_Bookings()
{
	int i = 0;
	while (i < num_Bookings)
	{
		cout << i + 1 << ".\n";
		cout << "Booker's CNIC: " << bookings[i].get_Cnic() << endl;
		cout << "Booking ID   : " << bookings[i].get_Booking_ID() << endl;
		cout << "Ticket Type  : " << bookings[i].get_Ticket_Type() << endl;
		cout << "Departure    : " << bookings[i].get_Trip_Departure() << endl;
		cout << "Destination  : " << bookings[i].get_Trip_Destination() << endl;
		cout << "Hotel Name   : " << bookings[i].get_Hotel_Name() << endl;
		cout << "Hotel Stay   : " << non_bookings[i].get_Hotel_Stay() << endl;
		cout << "Trip Cost    : " << bookings[i].get_Trip_Cost() << endl << endl;
		i++;
	}
}

Booking BookingController::unapproved_Booking_Shifting(int index)
{
	string dest = non_bookings[index].get_Trip_Destination();
	string dept = non_bookings[index].get_Trip_Departure();
	double cost = non_bookings[index].get_Trip_Cost();
	Hotel h;
	h.setHotelName(non_bookings[index].get_Hotel_Name());
	h.setHotelStay(non_bookings[index].get_Hotel_Stay());

	Booking obj;
	obj.shift_Booking_ID(non_bookings[index].get_Booking_ID());
	obj.set_Ticket_Type(non_bookings[index].get_Ticket_Type());
	obj.set_Cnic(non_bookings[index].get_Cnic());
	obj.setTrip(dept, dest, cost);
	obj.setHotel(h);

	remove_unapproved_Booking(index);
	new_unapproved_Data();

	return obj;
}

void BookingController::remove_unapproved_Booking(int index)
{
	Booking* tempArr = new Booking[maxBookings];
	for (int i = 0, j = 0; i < num_nonBookings; i++)
	{
		if (i != index)
		{
			tempArr[j] = non_bookings[i];
			j++;
		}
	}

	delete[] non_bookings;
	non_bookings = tempArr;
	num_nonBookings--;
}

void BookingController::remove_approved_Booking(int index)
{
	Booking* tempArr = new Booking[maxBookings];
	for (int i = 0, j = 0; i < num_Bookings; i++)
	{
		if (i != index)
		{
			tempArr[j] = bookings[i];
			j++;
		}
	}

	delete[] bookings;
	bookings = tempArr;
	num_Bookings--;
}

void BookingController::new_unapproved_Data()
{
	BookingDatabase data;
	ofstream outFile("unapprovedbookings.txt", ios::trunc);
	outFile.close();

	int temp = get_Num_nonBookings();
	set_Num_nonBookings();

	for (int i = 0; i < temp; i++)
	{
		Booking obj;
		Trip t;
		Hotel h;

		h.setHotelName(non_bookings[i].get_Hotel_Name());
		h.setHotelStay(non_bookings[i].get_Hotel_Stay());
		obj.setHotel(h);

		obj.setTrip(non_bookings[i].get_Trip_Departure(), non_bookings[i].get_Trip_Destination(), non_bookings[i].get_Trip_Cost());
		obj.shift_Booking_ID(non_bookings[i].get_Booking_ID());
		obj.set_Ticket_Type(non_bookings[i].get_Ticket_Type());

		data.store_unapproved_Booking_data(obj);
	}
}

void BookingController::new_approved_Data()
{
	BookingDatabase data;
	ofstream outFile("approvedbookings.txt", ios::trunc);
	outFile.close();

	int temp = num_Bookings;
	num_Bookings = 0;

	for (int i = 0; i < temp; i++)
	{
		Booking obj;
		Trip t;
		Hotel h;

		h.setHotelName(bookings[i].get_Hotel_Name());
		h.setHotelStay(bookings[i].get_Hotel_Stay());
		obj.setHotel(h);

		obj.setTrip(bookings[i].get_Trip_Departure(), bookings[i].get_Trip_Destination(), bookings[i].get_Trip_Cost());
		obj.shift_Booking_ID(bookings[i].get_Booking_ID());
		obj.set_Ticket_Type(bookings[i].get_Ticket_Type());
		obj.set_Cnic(bookings[i].get_Cnic());

		data.store_Approved_Bookings(obj);
	}
}

void BookingController::approved_Bookings(Booking obj)
{
	BookingDatabase data;
	data.store_Approved_Bookings(obj);
	num_Bookings = 0;
	data.load_approved_Bookings_Data();
}

void BookingController::load_approved_Bookings(Trip t, string tType, int id, string cnic, Hotel h)
{
	string dept = t.getDeparture();
	string dest = t.getDestination();
	double cost = t.getCost();

	bookings[num_Bookings].set_Cnic(cnic);
	bookings[num_Bookings].set_Ticket_Type(tType);
	bookings[num_Bookings].setTrip(dept, dest, cost);
	bookings[num_Bookings].shift_Booking_ID(id);
	non_bookings[num_nonBookings].setHotel(h);
	num_Bookings++;
}

void BookingController::load_Cancelled_Bookings(Trip t, string  tType, int  id, string cnic, Hotel h)
{
	string dept = t.getDeparture();
	string dest = t.getDestination();
	double cost = t.getCost();

	cancelled_Bookings[bookings_Cancelled].set_Cnic(cnic);
	cancelled_Bookings[bookings_Cancelled].set_Ticket_Type(tType);
	cancelled_Bookings[bookings_Cancelled].setTrip(dept, dest, cost);
	cancelled_Bookings[bookings_Cancelled].shift_Booking_ID(id);
	cancelled_Bookings[bookings_Cancelled].setHotel(h);
	bookings_Cancelled++;
}

int BookingController::booking_Status(int id)
{
	int i = 0;
	while (i < num_Bookings || i < bookings_Cancelled || i < num_nonBookings)
	{
		if (bookings[i].get_Booking_ID() == id)
		{
			return 1;
		}

		else if (non_bookings[i].get_Booking_ID() == id)
		{
			return 2;
		}

		else if (cancelled_Bookings[i].get_Booking_ID() == id)
		{
			return 3;
		}
		i++;
	}
	return 0;
}

bool BookingController::show_Customers_Bookings(string Cnic)
{
	int i = 0;
	bool flag1 = false, flag2 = false;

	cout << "\n\t\t\tYour Bookings:\n";

	while (i < num_nonBookings)
	{
		if (non_bookings[i].get_Cnic() == Cnic)
		{
			cout << endl;
			cout << "Booker's CNIC: " << non_bookings[i].get_Cnic() << endl;
			cout << "Booking ID   : " << non_bookings[i].get_Booking_ID() << endl;
			cout << "Ticket Type  : " << non_bookings[i].get_Ticket_Type() << endl;
			cout << "Departure    : " << non_bookings[i].get_Trip_Departure() << endl;
			cout << "Destination  : " << non_bookings[i].get_Trip_Destination() << endl;
			cout << "Trip Cost    : " << non_bookings[i].get_Trip_Cost() << endl << endl;
			flag1 = true;
		}
		i++;
	}

	int j = 0;
	while (j < num_Bookings)
	{
		if (bookings[j].get_Cnic() == Cnic)
		{
			cout << endl;
			cout << "Booker's CNIC: " << bookings[j].get_Cnic() << endl;
			cout << "Booking ID   : " << bookings[j].get_Booking_ID() << endl;
			cout << "Ticket Type  : " << bookings[j].get_Ticket_Type() << endl;
			cout << "Departure    : " << bookings[j].get_Trip_Departure() << endl;
			cout << "Destination  : " << bookings[j].get_Trip_Destination() << endl;
			cout << "Trip Cost    : " << bookings[j].get_Trip_Cost() << endl << endl;
			flag2 = true;
		}
		j++;
	}

	if (flag1 == true || flag2 == true)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool BookingController::cancelling_Booking(int id)
{
	int i = 0;
	bool flag = false;
	while (i < num_Bookings)
	{
		if (bookings[i].get_Booking_ID() == id)
		{
			remove_approved_Booking(i);
			new_approved_Data();
			flag = true;
		}
		i++;
	}

	i = 0;
	if (flag == false)
	{
		while (i < num_nonBookings)
		{
			if (non_bookings[i].get_Booking_ID() == id)
			{
				remove_unapproved_Booking(i);
				new_unapproved_Data();
				flag = true;
			}
			i++;
		}
	}

	return flag;
}

Booking BookingController::cancelled_Booking_By_Employee(int index)
{
	Booking obj;

	obj.shift_Booking_ID(non_bookings[index].get_Booking_ID());
	obj.set_Cnic(non_bookings[index].get_Cnic());
	obj.set_Ticket_Type(non_bookings[index].get_Ticket_Type());

	string dept = non_bookings[index].get_Trip_Departure();
	string dest = non_bookings[index].get_Trip_Destination();
	double cost = non_bookings[index].get_Trip_Cost();
	obj.setTrip(dept, dest, cost);

	Hotel h;
	h.setHotelName(non_bookings[index].get_Hotel_Name());
	obj.setHotel(h);

	remove_unapproved_Booking(index);
	new_unapproved_Data();

	return obj;
}

void BookingController::store_Cancelled_Bookings(Booking obj)
{
	BookingDatabase data;
	data.store_Cancel_Bookings(obj);
	bookings_Cancelled = 0;
	data.load_Cancel_Bookings();
}

bool BookingController::booking_Payment()
{
	char choose;
	int attempts = 3;

	while (true)
	{
		cout << "\nHow would you like to pay:\n\t1.Cash\n\t2.Online\n\t3.Credit Card\nChoose = ";
		cin >> choose;
		cin.ignore();

		if (choose == '1')
		{
			cout << "\nPayment Method [Cash]\n";
			return true;
		}
		else if (choose == '2')
		{
			cout << "\nPayment Method [Online]\n";
			cout << "\nAccount Details:\nBank Name: HBL\nAccount No # 0007383610\n";
			return true;
		}
		else if (choose == '3')
		{
			string creditCard;

			cout << "\nPayment Method [Credit Card]\n";
			cout << "Enter Card Details:\n";

			while (true)
			{
				bool checkcreditcard = true;
				int count = 0;

				cout << "Card No. = ";
				getline(cin, creditCard);

				while (creditCard[count] != '\0')
				{
					if (creditCard[count] < 48 || creditCard[count] > 57)
					{
						checkcreditcard = false;
						break;
					}
					count++;
				}

				if (checkcreditcard = false || count != 16)
				{
					cout << "\nInvalid Card No.!\n";
					attempts--;
					cout << attempts << " attempts remaining\n\n";
				}
				else
				{
					return true;
				}

				if (attempts == 0)
				{
					cout << "\nAll attempts are used\nExiting...\n";
					return false;
				}
			}
		}
		else
		{
			cout << "Invalid Input!";
			attempts--;
			if (attempts == 0)
			{
				return false;
			}
		}
	}
}

void BookingController::invoice_Data(Booking obj)
{
	cout << left;
	cout << "\nBooker's CNIC |-------------- " << setw(10) << obj.get_Cnic() << "\t|" << endl;
	cout << "Booking ID    |-------------- " << setw(10) << obj.get_Booking_ID() << "\t|" << endl;
	cout << "Ticket Type   |-------------- " << setw(10) << obj.get_Ticket_Type() << "\t|" << endl;
	cout << "Departure     |-------------- " << setw(10) << obj.get_Trip_Departure() << "\t|" << endl;
	cout << "Destination   |-------------- " << setw(10) << obj.get_Trip_Destination() << "\t|" << endl;
	cout << "Trip Cost     |-------------- " << setw(10) << obj.get_Trip_Cost() << "\t|" << endl;
	cout << "Payment Status|-------------- " << setw(10) << "Paid" << "\t|" << endl << endl;
}