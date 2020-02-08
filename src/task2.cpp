#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 16 // only kratno 2
void clearMatrix(char(*arr)[SIZE])//proBell
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			arr[i][j] = ' ';
}
void fillMatrix(char(*arr)[SIZE])//left side
{
	srand(time(NULL));
	for (int i = 0; i < SIZE / 2; i++)
		for (int j = 0; j < SIZE / 2; j++)
		{
			if (rand() % 2)
				arr[i][j] = '*';
		}
}
void setMatrix(char(*arr)[SIZE])//copy
{
	for (int i = 0; i < SIZE / 2; i++)
		for (int j = SIZE / 2; j < SIZE; j++)
			arr[i][j] = arr[i][SIZE - 1 - j];
	for (int i = 0; i < SIZE / 2; i++)
		for (int j = 0; j < SIZE; j++)
			arr[SIZE - 1 - i][j] = arr[i][j];
}
void printMatrix(char(*arr)[SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			putc(arr[i][j], stdout);
		putc('\n', stdout);
		clock_t begin = clock();
		while (clock() < begin + CLOCKS_PER_SEC);
	}
}