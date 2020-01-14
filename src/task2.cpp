#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "task2.h"

void clearMatrix(char(*arr)[M])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			arr[i][j] = ' ';
}

void fillMatrix(char(*arr)[M])
{
	int star;
	int i, j;
	int c = 0;

	if (M % 2 == 1)
		c = M / 2;
	else
		c = M / 2 - 1;

	for (i = 0; i < N/2; i++)
		for (j = 0; j < c; j++)
		{
			star = rand() % 2;
			if (star)
				arr[i][j] = '*';
		}
}

void setMatrix(char(*arr)[M])
{
	int i, j;
	int c = 0;

	if (M % 2 == 1)
		c = M / 2;
	else
		c = M / 2 - 1;


	for (i = 0; i < N / 2; i++)
	{
		for (j = 0; j < c; j++)
		{
			arr[i][c + j] = arr[i][j];
			arr[N / 2 + i][j] = arr[i][j];
			arr[N / 2 + i][c + j] = arr[i][j];
		}
		arr[i][c * 2] = '\0'; 
		arr[N / 2 + i][c * 2] = '\0';
	}

}

void printMatrix(char(*arr)[M])
{
	int i;
	for (i = 0; i < N; i++)
		printf("%s\n", arr[i]);
}