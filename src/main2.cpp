#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "task2.h"



int main(void)
{
	char buf[N][M];
	char (*arr)[M] = buf;
	
	for (int number = 0; number < 100; number++)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		clock_t begin = clock();
		int delay = 1000;
		while (clock() < begin + delay);
		system("cls");
	}
		
	getchar();
	return 0;
}