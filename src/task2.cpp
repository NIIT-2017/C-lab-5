#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
void clearMatrix(char (*arr)[M])
{
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M;j++)
		{
			arr[i][j] = ' ';
		}

	}

}

void fillMatrix(char(*arr)[M])
{
	for (int i = 0; i < M / 2; i++)
	{
		for (int j = 0; j < M / 2; j++)
		{
			srand(i+j +time(NULL));
			if (rand() % 2 == 1)
			{
				arr[i][j] = '*';
			}

		}

	}
}

void setMatrix(char(*arr)[M])
{
	for (int i = 0; i < M / 2; i++)
	{
		for (int j = 0; j < M / 2; j++)
		{
			arr[i][M - j - 1] = arr[i][j];
			arr[M - i - 1][j] = arr[i][j];
			arr[M - i - 1][M - j - 1] = arr[i][j];
		}
	}
}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
