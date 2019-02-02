#pragma warning(disable:4996)
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "task2.h"
#define M 20
void eraser()
{
	for (int i = 30; i > 0; i--)
	{
		printf("\n");
	}
}


int main()
{
	clock_t start = 0;
	clock_t delay = 1.5* CLOCKS_PER_SEC;
	srand(time(0));
	char arr[M][M];
	while (1)
	{
		clearMatrix(arr);
		printMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		start = clock();
		while (clock() - start < delay);
		eraser();
	}
	return 0;
}