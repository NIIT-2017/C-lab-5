#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"
#define SIZE 16
int main()
{
	char arr[SIZE][SIZE];
	while (1)
	{
		clearMatrix(arr);//proBell
		fillMatrix(arr);//left side
		setMatrix(arr);// copy
		system("cls");// clean monitor
		printMatrix(arr);
		clock_t begin = clock();
		while (clock() < begin + CLOCKS_PER_SEC * 2);// zaderzka na?
	}
	return 0;
}