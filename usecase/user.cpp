#include"user.h"

void User::set_Password(string password)
{
    Password = password;
}

string User::get_Password()
{
    return Password;
}

void User::set_Name(string name)
{
    Name = name;
}

string User::get_Name()
{
    return Name;
}

void User::set_Address(string ad)
{
    address = ad;
}

string User::get_Address()
{
    return address;
}

void User::set_Email(string em)
{
    email = em;
}

string User::get_Email()
{
    return email;
}

void User::set_Phone_Number(string No)
{
    phone_number = No;
}

string User::get_Phone_Number()
{
    return phone_number;
}