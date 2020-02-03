#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define M 20

void clearMatrix(char(*arr)[M])
{
	for (int i=0; i<M; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
}

void fillMatrix(char(*arr)[M])
{
	srand(time(NULL));
	for (int i = 0; i < M/2; i++)
		for (int j = 0; j < M/2; j++)
			if (rand() % 2)
				arr[i][j] = '*';
}

void setMatrix(char(*arr)[M])
{
	for (int i = 0; i < M / 2; i++)
		for (int j = 0; j < M / 2; j++)
		{
			arr[i][M-1 - j] = arr[i][j];
			arr[M-1 - i][j] = arr[i][j];
			arr[M-1 - i][M-1 - j] = arr[i][j];
		}
}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
}