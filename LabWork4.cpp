/*
Textbook Search Engine			
The purpose of this program is to develop the Reader function to fill an array with the contents of the Textbook.txt file (number of lines may not greater than 100). 
Once read operation is complete, ask the user to enter a word or phrase of a text title or author. 
Search the array for this information and print the result. Book title and author are separated with ‘%’ symbol.
The file named “Textbooks.txt” contains book information for books. Here are the first five lines of the file:
C++ is Easy % Moses Baca
Beginning Algebra % R. J. Gooding
Calculus for Dummies % R. Prairie
The C++ Complete Reference % Herbert Schlidt
C++ Programming Today % B. Johnston
Write your name to the screen.  Call the Reader function which returns a bool indicating success or failure for reading file.   
In main function, ask the user to input a word or phrase that is part of the title or the author’s name.  
Pass this string array which contains content of the file, and a result string array to a Search function.  
The Search function fills the result with the strings that contain the requested word/phrase.  From main, write the resultant text information.  
Here is an example of what your output might look like:
---------------------------------------------------------------------------------------------------------------
Text Book Search Engine
Enter a portion of title or author that you are looking for:  C++
There are 6 results for C++ :
Book Title: C++ is Easy 
Moses Baca

Book Title:The C++ Complete Reference 
Author: Herbert Schlidt

Book Title:C++ Programming Today 
Author: B. Johnston

Book Title:Java and C++ is Not For Wimps 
Author: E. Wilkinson

Book Title:Writing Accounting Programs in C++ 
Author: D. Addington

Book Title:C# is Better than C++ 
Author: Steve Parratto

Would you like to go again (yes/no)? yes



Enter a portion of title or author that you are looking for: Easy
There are 5 results for Easy:
Book Title: C++ is Easy 
Author: Moses Baca

Book Title: Easy Oracle 
Author: Brenda Judd

Book Title: Statistics Made Easy 
Author:  J. Baca

Book Title: Counting is Easy as 123 
Author: C. Dracula

Book Title: Oracle Academy Made Easy 
Author: Brenda Judd


Would you like to go again (yes/no)?no
Bye…..
---------------------------------------------------------------------------------------------------------------------

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


bool reader (string books[], int * size){
	fstream file1;

	file1.open("Textbooks.txt",ios::in);
	if(!file1.is_open()) return 0;

	int count=0;

	while(!file1.eof()){

		getline(file1,books[count]);
		count++;
	}
		*size=count;

		return 1;
}

void search(string books[], int size, string find){
	int result,pos,count=0;


	for(int i =0; i< size; i++){
		result= books[i].find(find);
		if(result != string::npos){
			count++;
		}
	}
		if(count==0){ cout << "NOT FOUND" <<endl; return; }
		cout << "There are "<< count <<" results for "<< find << endl;
		
		
		for(int i =0; i< size; i++){
		result= books[i].find(find);
		
		if(result != string::npos){
			pos=books[i].find("%");
			cout << books[i].substr(0,pos) << endl << books[i].substr(pos+2) << endl;
		}
		
	}
	
}
	

int main(){

	string books[100];
	int size;

	reader(books,&size);

	cout << "Melihsah AKIN" << endl;
	
	string find;
	char input;

	while(1){
		cout << "Enter a portion of title or author that you are looking for: ";
		cin >> find;
		search(books,size,find);
		cout << "Would you like to go again (yes/no)?";
		cin >> input;
		if(input =='n' || input=='N') break;
		
	}
	cout << endl << "BYE";
	

	return 1;
}

