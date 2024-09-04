#include"employeedatabase.h"
#include"employeecontroller.h"

void EmployeeDatabase::store_Employee_Data(string id, string pass, string name, string adr, string email, string position, string no, float salary)
{
	ofstream outData;
	outData.open("employeedata.txt",ios_base::app);
	outData << id + "\n";
	outData << pass + "\n";
	outData << name + "\n";
	outData << adr + "\n";
	outData << email + "\n";
	outData << position + "\n";
	outData << no + "\n";
	outData << salary << "\n:";
	outData.close();
}

void EmployeeDatabase::load_Employee_Data()
{
	ifstream inData("employeedata.txt");
	EmployeeController* ptr = EmployeeController::getInstance();
	ptr->setnumEmployees();

	while (inData.eof() == 0)
	{
		string id, pass, name, address, email, no, position;
		float salary;
		getline(inData, id, '\n');
		
		getline(inData, pass, '\n');
		
		getline(inData, name, '\n');

		getline(inData, address, '\n');
		
		getline(inData, email, '\n');
		
		getline(inData, position, '\n');
		
		getline(inData, no, '\n');
		
		inData >> salary;
		inData.ignore(1, ':');
		inData.ignore(1, '\n');

		ptr->loading_Employee_Data(id, pass, name, address, email, position, no, salary);
	}
}