#include "SimpleDraw.h"

struct carInfo {
	int color[3];
	char plateNum[8];
	int rimSize;
	int rimColor[3];
}car1;

void main()
{
	bool err = true;
	printf("PLEASE ENTER THE RGB VALUES OF THE CAR: ");
	scanf("%d %d %d", &car1.color[0], &car1.color[1], &car1.color[2]);

	printf("PLEASE ENTER THE PLATE NUMBER: ");
	fflush(stdin);
	scanf("%s", car1.plateNum);
while(err==true){
	printf("PLEASE ENTER THE RIM SIZE ( IN PIXEL ): ");
	fflush(stdin);
	scanf("%d", &car1.rimSize);
	if (car1.rimSize>50) {
		printf("I THINK IT'S TOO BIG\n");
		if (err == true) printf("TIP: ENTER THE RIM SIZE BETWEEN 30 and 50\n");
		err = true;
		continue;
	}
	else if (car1.rimSize<30) {
		printf("I THINK IT'S TOO SMALL\n");
		if (err == true) printf("TIP: ENTER THE RIM SIZE BETWEEN 30 and 50\n");
		err = true;
		continue;
	}
err=false;
}
	printf("PLEASE ENTER THE RGB VALUES OF THE RIM: ");
	scanf_s("%d %d %d", &car1.rimColor[0], &car1.rimColor[1], &car1.rimColor[2]);



	setWindowSize(740, 500);



	useBrush(1, RGB(255, 255, 255));
	int p2[][2] = { { 170,200 },{ 250,100 },{ 450,100 },{ 550,200 } };
	drawPolygon(p2, 4);
	drawLine(450, 95, 555, 200);
	drawLine(250, 95, 165, 200);


	useBrush(1, RGB(car1.color[0], car1.color[1], car1.color[2]));
	drawRectangle(250, 95, 450, 100);
	drawRectangle(25, 200, 690, 350);

	useBrush(2, RGB(car1.color[0], car1.color[1], car1.color[2]));
	drawRectangle(25, 325, 125, 350);
	drawLine(170, 200, 170, 350);
	drawLine(550, 200, 550, 350);

	drawText(40, 330, car1.plateNum);

	useBrush(1, RGB(0, 0, 0));
	drawCircle(170, 350, 60);
	drawCircle(550, 350, 60);
	useBrush(1, RGB(car1.rimColor[0], car1.rimColor[1], car1.rimColor[2]));
	drawCircle(170, 350, car1.rimSize);
	drawCircle(550, 350, car1.rimSize);

	drawLine(350, 100, 350, 350);

	useBrush(1, RGB(255, 255, 255));
	drawRectangle(365, 225, 400, 235);
	drawRectangle(190, 225, 225, 235);


	while (!getMouseButton());



}