#include "Student.h"
#include "Teacher.h"
#define studentLimit 30
#define courseLimit 20
#define teacherLimit 10
int menu();
Student createStudent(string,string,int);
void addStudent(Student[], int*);
Teacher createTeacher(string, string, int);
void addTeacher(Teacher[], int*);
Course createCourse(string, string);
void addCourse(Course[], int*);
void display(Student[], int);
void display(Teacher[], int);
void display(Course[], int);
void addACourseTo(Student[], int, Course[], int);
void addACourseTo(Teacher[], int, Course[], int);
void removeCourse(Student[], int);
void removeCourse(Teacher[], int);
void listCourse(Student);
void listCourse(Teacher);
void listOFCoursesSomeone(Student[], int);
void listOFCoursesSomeone(Teacher[], int);
void listOfStudent(Course[], int,Student[],int);
int main()
{
	Student studentArr[studentLimit];
	Course courseArr[courseLimit];
	Teacher teacherArr[teacherLimit];
	int studentSize = 0, courseSize = 0, teacherSize = 0;


	int selection = -1;
	while(selection!=0){
		selection = menu();
		switch (selection)
	{
	case 1:
		addStudent(studentArr, &studentSize);	
		break;
	case 2:
		addTeacher(teacherArr, &teacherSize);
		break;
	case 3:
		addCourse(courseArr, &courseSize);
		break;
	case 4:
		addACourseTo(studentArr, studentSize, courseArr, courseSize);
		break;
	case 5:
		addACourseTo(teacherArr, teacherSize, courseArr, courseSize);
		break;
	case 6:
		removeCourse(studentArr, studentSize);
		break;
	case 7:
		removeCourse(teacherArr, teacherSize);
		break;
	case 8:
		display(studentArr, studentSize);
		break;
	case 9:
		display(courseArr, courseSize);
		break;
	case 10:
		display(teacherArr, teacherSize);
		break;
	case 11:
		listOFCoursesSomeone(studentArr, studentSize);
		break;
	case 12:
		listOFCoursesSomeone(teacherArr, teacherSize);
		break;
	case 13: 
		listOfStudent(courseArr, courseSize, studentArr, studentSize);
		break;
	}

	}

	return 0;
}

int menu()
{
	int selection;
	cout << "1) Create a student" << endl
		<< "2) Create a teacher" << endl
		<< "3) Create a course" << endl
		<< "4) Add a course to course list of a student" << endl
		<< "5) Add a course to course list of a teacher" << endl
		<< "6) Remove course from course list of a student" << endl
		<< "7) Remove course from course list of a teacher" << endl
		<< "8) Display the list of students" << endl
		<< "9) Display the list of courses" << endl
		<< "10) Display the list of teachers" << endl
		<< "11) Display the list of courses which are taken by a student" << endl
		<< "12) Display the list of courses which are given by a teacher" << endl
		<< "13) Display the list of students who takes a course" << endl
		<< "0) Exit" << endl;
	cin >> selection;
	return selection;
}

Student createStudent(string name, string surname, int number)
{
	Student newStudent(name, surname, number);
	return newStudent;
}

void addStudent(Student arr[], int * size)
{
	if (*size == studentLimit) return;
	string name, surname;
	int number;

	cout << "Enter a name, surname and number";
	cin >> name >> surname >> number;

	arr[(*size)] = createStudent(name, surname, number);
	++(*size);
}

Teacher createTeacher(string name, string surname, int number)
{
	Teacher newTeacher(name, surname, number);
	return newTeacher;
}

void addTeacher(Teacher arr[], int * size)
{
	if (*size == teacherLimit) return;
	string name, surname;
	int number;

	cout << "Enter a name, surname and registration number";
	cin >> name >> surname >> number;

	arr[(*size)] = createTeacher(name, surname, number);
	++(*size);
}

Course createCourse(string code, string name)
{
	Course newCourse;
	newCourse.setCName(name);
	newCourse.setCode(code);
	return newCourse;
}
void addCourse(Course arr[], int * size)
{
	if (*size == courseLimit) return;
	string code, cName;
	cout << "Enter a course code";
	cin >> code;
	cout << "Enter the course name";
	cin >> cName;	

	arr[(*size)] = createCourse(code, cName);
	++(*size);
}

void display(Student arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ") ";
		arr[i].display();
	}
}

void display(Teacher arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ") ";
		arr[i].display();
	}
}

void display(Course arr[], int size)
{
	for (int i = 0; i < size; i++) 
	{
		cout << (i + 1) << ") ";
		arr[i].display();
	}
}

void addACourseTo(Student arrS[], int sSize, Course arrC[], int cSize)
{
	int selectedStudent, selectedCourse,i=0;
	cout << "Select a student" << endl;
	display(arrS, sSize);
	cin >> selectedStudent;
	cout << "Select a course" << endl;
	display(arrC, cSize);
	cin >> selectedCourse;
	arrS[selectedStudent - 1].addCourse(arrC[selectedCourse - 1]);
}

void addACourseTo(Teacher arrT[], int tSize, Course arrC[], int cSize)
{
	int selectedTeacher, selectedCourse, i = 0;
	cout << "Select a teacher" << endl;
	display(arrT, tSize);
	cin >> selectedTeacher;
	cout << "Select a course" << endl;
	display(arrC, cSize);
	cin >> selectedCourse;
	arrT[selectedTeacher - 1].addCourse(arrC[selectedCourse - 1]);
}
void listCourse(Student one)
{
	one.listOfCourse();
}

void listCourse(Teacher one)
{
	one.listOfCourse();
}
void removeCourse(Student arr[], int sSize)
{
	int selectedStudent, selectedCourse;
	cout << "Select a student" << endl;
	display(arr, sSize);
	cin >> selectedStudent;
	cout << "Select course which will be removed" << endl;
	listCourse(arr[selectedStudent - 1]);
	cin >> selectedCourse;
	arr[selectedStudent - 1].removeCourse(selectedCourse - 1);
}

void removeCourse(Teacher arr[], int tSize)
{
	int selectedTeacher, selectedCourse;
	cout << "Select a Teacher" << endl;
	display(arr, tSize);
	cin >> selectedTeacher;
	cout << "Select course which will be removed" << endl;
	listCourse(arr[selectedTeacher - 1]);
	cin >> selectedCourse;
	arr[selectedTeacher - 1].removeCourse(selectedCourse - 1);
}


void listOFCoursesSomeone(Student arr[], int sSize)
{
	int selectedStudent;
	cout << "Select a student" << endl;
	display(arr, sSize);
	cin >> selectedStudent;
	listCourse(arr[selectedStudent -1]);
}

void listOFCoursesSomeone(Teacher arr[], int tSize)
{
	int selectedTeacher;
	cout << "Select a teacher" << endl;
	display(arr, tSize);
	cin >> selectedTeacher;
	listCourse(arr[selectedTeacher -1]);
}

void listOfStudent(Course arr[], int size, Student studentArr[], int sSize)
{
	int selectedCourse;
	cout << "Select a course" << endl;
	display(arr, size);
	cin >> selectedCourse;

	for (int i = 0; i < sSize; i++)
	{
		if (studentArr[i].findCourse(arr[selectedCourse - 1].getCode())) studentArr[i].display();

	}
}