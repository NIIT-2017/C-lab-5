#include "task2.h"
#include <time.h>
#include <stdlib.h>
#define M 20

void delay(clock_t sec)
{
	clock_t start_time = clock();
	clock_t end_time = sec + start_time;
	while (clock() != end_time);
}

int main()
{
	char arrive[M][M];
	while (1)
	{
		clearMatrix(arrive);
		fillMatrix(arrive);
		setMatrix(arrive);
		printMatrix(arrive);
		delay(1000);
		system("cls");
	}
	return 0;
}