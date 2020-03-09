#include "task2.h"

void clearMatrix(char(*arr)[SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void fillMatrix(char(*arr)[SIZE])
{
	srand(time(NULL));
	for (int i = 0; i < SIZE/2; i++)
	{
		for (int j = 0; j < SIZE/2; j++)
		{
			char ch = ' ';
			if (rand() % 2)
				ch = '*';

			arr[i][j] = ch;
		}
	}

}

void setMatrix(char(*arr)[SIZE])
{
for (int i = 0; i < SIZE / 2; i++)
	for (int j = SIZE / 2; j < SIZE; j++)
		arr[i][j] = arr[i][SIZE - j - 1];
for (int i = 0; i < SIZE / 2; i++)
	for (int j = 0; j < SIZE; j++)
		arr[SIZE - i - 1][j] = arr[i][j];
}

void printMatrix(char(*arr)[SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%5c", arr[i][j]);
		}
		printf("\n");
	}
}
