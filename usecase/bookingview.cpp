#include"bookingview.h"
#include"tripdatabase.h"
#include "customercontroller.h"

string BookingView::ticket_Type_in()
{
	char choose;
	cout << "\nTicket Type:\n1. Returning\n2. Not-Returning\n";
	cin >> choose;

	if (choose == '1')
	{
		ticketType = "Returning";
	}

	else
	{
		ticketType = "Not-Returning";
	}

	return ticketType;
}

void BookingView::show_Trips()
{
	TripController* ptr = TripController::getInstance();
	ptr->display_Trips();
}

Trip BookingView::choose_Trip()
{
	int no, attempts = 3;
	Trip obj;
	TripController* ptr = TripController::getInstance();
	show_Trips();
	bool flag = true;


	while (flag)
	{
		cout << "\nEnter the respecive Trip No. to choose: ";
		cin >> no;
		no--;
		int index = ptr->get_numTrips();

		if (no < index)
		{
			obj = ptr->choosing_trip(no);
			flag = false;
		}
		else
		{
			cout << "\nWrong Trip No.\n";
			attempts--;
			cout << attempts << " attempts left\n";
			if (attempts == 0)
			{
				cout << "All attempts used!\n";
				flag = false;
			}
		}
	}


	return obj;
}

void BookingView::booking_Info(string CNIC)
{
	Trip obj = choose_Trip();

	HotelController* Hotel_ptr = HotelController::getInstance();
	Hotel_ptr->display_Hotels();
	Hotel h = Hotel_ptr->choose_Hotel();
	int days = Hotel_ptr->choose_Stay();

	h.setHotelStay(days);


	if (obj.getDeparture() != "" && obj.getDestination() != "" )
	{
		BookingController* Booking_ptr = BookingController::getInstance();
		CustomerController* Customer_ptr = CustomerController::getInstance();

		string tType = ticket_Type_in();
		bool flag = Booking_ptr->booking_Payment();
		if (flag)
		{
			Booking booking_Data = Booking_ptr->making_Booking(obj, tType, CNIC, h);
			Customer_ptr->customer_Invoice(booking_Data);
		}
		else
		{
			cout << "\nPayment Error!\nBooking not made.\n\n";
		}
	}

	else
	{
		cout << "\nInvalid Information!\n";
	}
}

