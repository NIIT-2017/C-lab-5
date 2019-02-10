#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "task2.h"
#define N 6
#define M 10

int main()
{
	char arr[N][M] = { 0 };
	srand(time(0));
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		system("cls");
		printMatrix(arr);
		clock_t t = clock();
		while (clock() < t + CLOCKS_PER_SEC);	
	}
	return 0;
}