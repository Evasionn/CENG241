#include "CargoShip.h"
#include "CruiseShip.h"


void display(Ship &s) {
	cout << s.getCost() << endl;
}

int main()
{
	Ship s1(2008, "Allure of the Seas", 1500);
	display(s1);
	CruiseShip s2("Freedom of the Seas", 2005, 3621, 3000);
	display(s2);
	CargoShip s3("MSC Newyork", 2014, 18270, 5000);
	display(s3);

	s1.display();
	s2.display();
	s3.display();
	return 0;
}