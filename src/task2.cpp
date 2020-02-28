#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"

void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void fillMatrix(char(*arr)[M])
{
	srand(time(NULL));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M/2; j++)
		{
		if(rand() % 2)
            {
                char c = '*';
                arr[i][j] = c;
            }
		}
	}
}
void setMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M / 2; j++)
		{
			arr[M - 1 - i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M / 2; j++)
		{
			arr[i][M - 1 - j] = arr[i][j];
		}
	}
}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%5c", arr[i][j]);
		}
		printf("\n");
	}
}
