#include "task2.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	char arr[M][M] = { NULL };
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		system("cls");
		printMatrix(arr);
		_sleep(1000);
	}
	return 0;
}