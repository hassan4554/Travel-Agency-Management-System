#pragma once
#ifndef CUSTOMERDATABASE_H
#define CUSTOMERDATABASE_H
#include<iostream>
#include<string>
#include<fstream>
#include"customercontroller.h"
using namespace std;

class CustomerDatabase
{
public:
	void store_Customer_Data(string, string, string, string, string, string, string);
	void load_Customer_Data();
};
#endif