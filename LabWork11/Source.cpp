#include "CargoShip.h"
#include "CruiseShip.h"

void printArray(CargoShip arr[], int size)
{
	for (int i = 0; i < size; i++) arr[i].display();
}
void printArray(CruiseShip arr[], int size)
{
	for (int i = 0; i < size; i++) arr[i].display();
}
void printArray(CargoShip * arr[], int size)
{
	for (int i = 0; i < size; i++) arr[i]->display();
}
int main()
{
	CruiseShip clist[] = {
		CruiseShip("Allure of the Seas",2008,5400),
		CruiseShip("Freedom of the Seas",2005,3621),
		CruiseShip("Carnival Freedom",2007,2974)
	};

	CargoShip cargoList[] = {
		CargoShip("MSC Newyork",2014,18270),
		CargoShip("Madison Maersk",2005,16020),
		CargoShip("Hyundai Together",2012,13100)
	};

	printArray(clist, 3);

	cout << endl << endl;
	printArray(cargoList, 3);


	CargoShip * cargoList2[] = {
		new CargoShip("MSC Newyork",2014,18270),
		new CargoShip("Madison Maersk",2005,16020),
		new CargoShip("Hyundai Together",2012,13100)
	};

	cout << endl << endl;
	printArray(cargoList2, 3);
	return 0;
}