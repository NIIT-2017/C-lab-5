#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"


int main()
{
	char arr[N][M];
	srand((unsigned int)time(0));
	clock_t t = clock();
	while (clock() < t + 20000)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		system("cls");
		setMatrix(arr);
		printMatrix(arr);
		clock_t t = clock();
		while (clock() < t + CLOCKS_PER_SEC);
	}
	return 0;
}