#include<stdio.h>
#include<time.h>
#include"task2.h"

int main()
{
	char arr[N][M] = { 0 };

	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);

		clock_t begin = clock();
		while (clock() < begin + CLOCKS_PER_SEC); //time delay
	}

	return 0;
}