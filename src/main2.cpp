#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "task2.h"


int main()
{
	char arr[M][M] = { 0 };
	srand(time(0));
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		//system("cls");
		system( "clear" );
		printMatrix(arr);
		clock_t begin = clock();
		int delay = 1000;
		while (clock() < begin + delay);
	}
	return 0;
}