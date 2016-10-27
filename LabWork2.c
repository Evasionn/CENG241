/*
We used three structs which are ‘Automobile’, ‘Brand’ and ‘Model’ in lab work of past week, for example, we have used only one Brand for Automobile. 
In this week, you must design completely dynamic program. In other words, Automobile can contain more than one Brand and also Brand can contain more than one model. 
Design a menu driven program:

1. Brand
2. Model

If the user selects 1 from the main menu, you should display following menu:

1.	Add a new Brand
2.	Display all Brand
3.	Remove Brand (also remove all Models under the Brand)
4.	Change Brand information

If the user selects 1 from the menu, you should dynamically increase the size of the array and then add a Brand.

If the user selects 2 from the menu, you should display all Brand names. 

In menu items 3 and 4, you should firstly find related Brand which is entered by the user and then you can remove or change Brand. 

If the user selects 2 from the main menu, you should list all Brand names and user selects one of them. After the brand selection, you should display following menu:

1.	Add a new Model
2.	Display all Model

If the user selects 1 from the menu, you should dynamically increase the size of the array and then add a Model.

If the user selects 2 from the menu, you should display all Model info under the selected Brand. 

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int age;
	int km;
	char color[10];
}Model;

typedef struct
{
	char bname[10];
	Model *m;
	int mSize;
}Brand;

typedef struct
{
	Brand *b;
	int bSize;

}Automobile;


Automobile* createAutomobile()
{
	Automobile *a = (Automobile *)malloc(sizeof(Automobile));
	a->bSize = 0;
	a->b = NULL;
	return a;
}

Brand createBrand(char *bname)
{
	Brand b;
	strcpy(b.bname, bname);
	b.m = NULL;
	b.mSize = 0;
	return b;
}

Model createModel(int age, char *color, int km)
{
	Model m;
	m.age = age;
	m.km = km;
	strcpy(m.color, color);
	return m;
}


int findIndex(Automobile * a) {
	char bName[10];
	puts("Enter a brand name");

	scanf("%s", bName);
	int i = 0;
	bool flag = false;
	for (i; i < a->bSize; i++) {
		if (strcmp(bName, a->b[i].bname) == 0) {
			flag = true;
			break;
		}
	}
	if (flag == true) return i;
	else return -1;
}


void addModel(Automobile *a)
{
	char color[20];
	int age;
	int km;

	if (a != NULL && a->bSize != 0)
	{
		int index = findIndex(a);
		if (index > -1) {
			printf("Enter color, age and km");
			scanf("%s%d%d", color, &age, &km);
			Model m = createModel(age, color, km);
			a->b[index].m = (Model *)realloc(a->b[index].m, sizeof(Model)*(a->b[index].mSize + 1));
			a->b[index].m[(a->b[index].mSize)] = m;
			a->b[index].mSize++;
		}
	}
	else
		printf("You must create Automobile and Brand\n");
}

void addBrand(Automobile *a)
{
	char bname[10];

	if (a != NULL) {


		printf("Enter a brand name");
		scanf("%s", bname);
		Brand b = createBrand(bname);
		a->b = (Brand *)realloc(a->b, sizeof(Brand)*((a->bSize) + 1));
		a->b[a->bSize] = b;
		a->bSize++;
	}
	else
		printf("You must create Automobile");
}


void displayAllBrand(Automobile *a) {
	for (int i = 0; i< a->bSize; i++) {
		printf("%s \n", a->b[i].bname);
	}
}

void removeBrand(Automobile *a) {
	int index = findIndex(a);

	if (index>-1) {
		a->b[index] = a->b[a->bSize - 1];
		a->bSize--;
		free(a->b[index].m);
		a->b = (Brand *)realloc(a->b, sizeof(Brand)* a->bSize);
		

	}
	else printf("Brand name couldn't be found.");
}

void changeBrandInformation(Automobile *a) {

	int index = findIndex(a);
	if (index>-1) {
		char newname[10];
		puts("Enter new brand name");
		scanf("%s", newname);
		strcpy(a->b[index].bname, newname);
	}
	else printf("Brand name couldn't be found.");

}

void displayAllModel(Automobile *a) {
	int index = findIndex(a);
	if (index > -1) {
		for (int i = 0; i < a->b[index].mSize; i++) {
			printf("%s\n%d\n%d\n\n", a->b[index].m[i].color, a->b[index].m[i].age, a->b[index].m[i].km);
		}
	}
}
int mainMenu()
{
	int selection;
	puts("1. Brand");
	puts("2. Model");
	puts("0. Exit");
	scanf("%d", &selection);
	return selection;
}

int brandMenu()
{
	int selection;
	puts("1.	Add a new Brand");
	puts("2.	Display all Brand");
	puts("3.	Remove Brand (also remove all Models under the Brand)");
	puts("4.	Change Brand information");
	puts("0.	Return Main Menu");
	scanf("%d", &selection);
	return selection;
}

int modelMenu()
{
	int selection;
	puts("1.	Add a new Model");
	puts("2.	Display all Model");
	puts("0.	Return Main Menu");
	scanf("%d", &selection);
	return selection;
}




int main()
{
	char search[10];
	Automobile *a = createAutomobile();
	int selection = -1;
	while (selection != 0)
	{
		selection = mainMenu();
		switch (selection)
		{
		case 1:
			selection = brandMenu();
			if (selection == 1)
			{
				addBrand(a);
			}
			else if (selection == 2)
			{
				displayAllBrand(a);
			}
			else if (selection == 3)
			{

				removeBrand(a);
			}
			else if (selection == 4)
			{
				changeBrandInformation(a);
			}
			else if (selection == 0) selection = -1;
			break;

		case 2:
			selection = modelMenu();
			if (selection == 1) {
				addModel(a);
			}
			else if (selection == 2) {
				displayAllModel(a);
			}
			else if (selection == 0) selection = -1;
			break;


		}
	}



}
