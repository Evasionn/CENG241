/*
Write a complete C program which consists of 3 structures called as ‘Automobile’, ‘Brand’ and ‘Model’. 
‘Automobile’ structure only contains a pointer type of ‘Brand’. ‘Brand’ structure contains a brand name and a pointer type of ‘Model’.  
For the ‘Model’ structure, it contains color, car age, kilometer. Furthermore, you should dynamically allocate memory for pointers in structures. 
*/
/*
 * source.c
 *
 *  Created on: 8 Eki 2016
 *      Author: melihsah
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
	MODEL *m;
}BRAND;

typedef struct
{
	BRAND *b;

}AUTOMOBILE;

BRAND* createBrand(char *arr)
{
	BRAND *b= (BRAND *) malloc(sizeof(BRAND)) ;
	strcpy(b->bname, arr);
	b->m = NULL;
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
	return ca;
}
void addBrand(AUTOMOBILE *a)
{
	if(a->b !=NULL)
	{
		free(a->b);
	}
	a->b = createBrand("XYZ");
}
void addModel(AUTOMOBILE *a)
{
	int age;
	char color[20];
	int km;
	if(a->b == NULL)
		printf("You must create Brand");
	else
	{
		if(a->b->m != NULL)
		{
			free(a->b->m);
		}
		printf("Enter age, color, km");
		scanf("%d%s%d",&age,color,&km);
		a->b->m = createModel(age,color,km);
	}
}

void Display(AUTOMOBILE *a)
{	
	if(a!=NULL && a->b !=NULL && a->b->m != NULL)
		printf("%s %d %d %s",a->b->bname, a->b->m->age,a->b->m->km,a->b->m->color);
}




int main()
{
	AUTOMOBILE *a;
	a= createAutomobile();
	addBrand(a);
	addModel(a);
	Display(a);

}