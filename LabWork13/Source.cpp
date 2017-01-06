#include "List.h"


int main()
{
	List<int> myList,myList2;
	
	myList << 10;
	myList << 15;
	myList << 5;

	myList2 = myList;

	myList.sortArray();


	cout << "First List:" << endl;
	myList.listArray();
	cout << "Second List:" << endl;
	myList2.listArray();
	if (myList == myList2)
	{
		cout << "These two lists are equal to each other."<<endl;
	}
	else
	{
		cout << "These two lists are NOT equal to each other."<<endl;
	}

	return 0;
}