#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"

int main()
{
	char arr[M][M] = { {0} };
	for (int i = 0; i < 3; i++)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		clock_t begin = clock();
		while (clock() < begin + CLOCKS_PER_SEC);
	}
	return 0;
}