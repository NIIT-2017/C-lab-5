#include "task2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define M 20

int main()
{
	time_t now;
	time(&now);
	srand(now);
	char Mat[M][M];
	while (1)
	{
		clearMatrix(Mat);
		fillMatrix(Mat);
		setMatrix(Mat);
		printMatrix(Mat);
		clock_t begin = clock();
		while (clock() < begin + CLOCKS_PER_SEC);
		system("cls"); // очистка консоли
	}
	return 0;
}