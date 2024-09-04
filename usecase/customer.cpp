#include "customer.h"

void Customer::set_Username(string username)
{
    Username = username;
}

string Customer:: get_Username()
{
    return Username;
}

void Customer::set_CNIC(string cnic)
{
    CNIC = cnic;
}

string Customer::get_CNIC()
{
    return CNIC;
}

void Customer::Display() {
    cout << "Name: " << get_Name() << endl;
    cout << "Username: " << get_Username() << endl;
    cout << "CNIC: " << get_CNIC() << endl;
    cout << "Email: " << get_Email() << endl;
    cout << "Phone Number: " << get_Phone_Number() << endl;
    cout << "Address: " << get_Address() << endl;
}