/*

In this lab work, you try to combine the first week lab experiment with last week lab experiment, namely Automobile can contain more than one pointer type of Brand. 
Also, Brand can contain more than one pointer type of Model. You must arrange your previous labwork according to the situation mentioned above. 
User can enter more than one brand, so your automobile struct must keep the address of all of the user entered brand. 
According to the situation, your automobile struct change as follow:

typedef struct {
	Brand **b;
	int size;
} Automobile;

You should change your Model struct by using Automobile struct as base. Also, design menu driven program like previous week.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char color[20];
	int age;
	int km;
}MODEL;

typedef struct
{
	char bname[20];
	MODEL **m;
	int mSize;
}BRAND;

typedef struct
{
	BRAND **b;
	int bSize;

}AUTOMOBILE;

BRAND* createBrand(char *arr)
{
	BRAND *b=(BRAND *) malloc(sizeof(BRAND)) ;
	strcpy(b->bname, arr);
	b->m = NULL;
	b->mSize = 0;
	return b;	
}
MODEL* createModel(int age, char *color, int km)
{
	MODEL *c=(MODEL *) malloc(sizeof(MODEL));
	c->age=age;
	strcpy(c->color,color);
	c->km=km;
	return c;
}

AUTOMOBILE* createAutomobile()
{
	AUTOMOBILE *ca = (AUTOMOBILE *)malloc(sizeof (AUTOMOBILE));
	ca ->b = NULL;
	ca->bSize = 0;
	return ca;
}
void addBrand(AUTOMOBILE *a)
{
	char bname[20];
	if(a!=NULL)
	{
		printf("Enter Brand Name");
		scanf("%s",bname);
		BRAND *b = createBrand(bname);

		(a->b) = (BRAND **)realloc((a->b), sizeof(BRAND)*(a->bSize+1));
		a->b[a->bSize] = b;
		a->bSize++;

	}
	
}

int findIndex(AUTOMOBILE *a){
	char bname[20];
	printf("Enter Brand Name");
	scanf("%s",bname);
	int i = 0 ;
	for(i; i < a->bSize; i ++){
		if(strcmp(bname,a->b[i]->bname)==0) return i;
	}
	return -1;
}
void addModel(AUTOMOBILE *a)
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
			MODEL *m = createModel(age, color, km);

			a->b[index]->m = (MODEL **)realloc(a->b[index]->m,sizeof(MODEL) * (a->b[index]->mSize + 1));
			a->b[index]->m[(a->b[index]->mSize)] = m;
			a->b[index]->mSize++;
		}
	}
	else
		printf("You must create Automobile and Brand\n");
}


void displayAllBrand(AUTOMOBILE *a){
	int i =0;
	for(i ; i < a->bSize; i++){
		printf("%s\n", a->b[i]->bname);
	}
}



void changeBrandInformation(AUTOMOBILE *a) {

	int index = findIndex(a);
	if (index>-1) {
		char newname[10];
		puts("Enter new brand name");
		scanf("%s", newname);
		strcpy(a->b[index]->bname, newname);
	}
	else printf("Brand name couldn't be found.");

}
void removeBrand(AUTOMOBILE *a) {
	int index = findIndex(a);

	if (index>-1) {
		a->b[index] = a->b[a->bSize - 1];
		a->bSize--;
		free(a->b[index]->m);
		a->b = (BRAND **)realloc(a->b, sizeof(BRAND)* a->bSize);
		

	}
	else printf("Brand name couldn't be found.");
}
int DisplayBrandMenu()
{
	int selection;
	puts("1.	Add a new Brand");
	puts("2.	Display all Brand");
	puts("3.	Remove Brand (also remove all Models under the Brand)");
	puts("4.	Change Brand information");

	scanf("%d",&selection);
	return selection;
}
void displayAllModel(AUTOMOBILE *a) {
	int index = findIndex(a);
	if (index > -1) {
		for (int i = 0; i < a->b[index]->mSize; i++) {
			printf("%s\n%d\n%d\n\n", a->b[index]->m[i]->color, a->b[index]->m[i]->age, a->b[index]->m[i]->km);
		}
	}
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
int main()
{
	
	AUTOMOBILE *a = createAutomobile();
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