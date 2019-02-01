#include <iostream>
#include <ctime>
#include <stdio.h>
#define Symbol '*'
#define M 30

void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < M - 2; i++)
		for (int j = 0; j < M - 2; j++)
			arr[i][j] = ' ';
}

void fillMatrix(char(*arr)[M])
{
	for (int i = 0; i < M / 2 - 1; i++)
		for (int j = 0; j < M / 2 - 1; j++)
		{
			srand(time(0) + i + j);
			if (rand() % 2 == 1)
				arr[i][j] = Symbol;
		}
}

void setMatrix(char(*arr)[M])
{
	for (int i = 0; i < M / 2 - 1; i++)
		for (int j = 0; j < M / 2 - 1; j++)
		{
			arr[M - i - 3][M - j - 3] = arr[i][j];
			arr[M - i - 3][j] = arr[i][j];
			arr[i][M - j - 3] = arr[i][j];
		}
}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M - 2; i++)
	{
		arr[i][M - 2] = '\0';
		puts(arr[i]);
	}

}