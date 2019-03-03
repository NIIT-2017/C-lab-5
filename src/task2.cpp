#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "task2.h"

void clearMatrix(char(*arr)[M]) // filling up with spaces
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
}

void fillMatrix(char(*arr)[M]) // bilding the first left field
{
	srand(time(NULL));
	for (int i = 0; i <= (N / 2 - 1); i++)
		for (int j = 0; j <= (M / 2 - 1); j++)
			if (rand() % MP == 0)
				arr[i][j] = '*';
}

void setMatrix(char(*arr)[M]) // setting the fields
{
	for (int i = 0; i < (N / 2); i++)
		for (int j = 0; j < (M / 2); j++)
			arr[i][M - 1 - j] = arr[i][j]; 
	for (int i = 0; i < (N / 2); i++)
		for (int j = 0; j < M; j++)
			arr[N - 1 - i][j] = arr[i][j]; 

}

void printMatrix(char(*arr)[M]) // let's get it printed
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c", arr[i][j]);
			if (j == M - 1)
				putchar('\n');
		}
	}
}