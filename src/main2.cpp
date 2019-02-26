#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"
#define N 30
#define M 50

int main()
{
	char arr[N][M] = { 0 };

	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		system("cls");
		printMatrix(arr);
		unsigned int retTime = time(0) + 1;
		while (time(0) < retTime);
	}
	return 0;
}