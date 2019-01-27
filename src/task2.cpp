#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"


void clearMatrix(char(*arr)[M])
{
	int i = 0, l;
	while (i < N)
	{
		for (l = 0; l < M; l++)
		{
			if (l == M-1)
			*(arr[i]+l) = '\0';
			else *(arr[i] + l) = ' ';
		}
		i++;
	}
}

void fillMatrix(char(*arr)[M])
{
	int random;
	srand(time(NULL));

	int i = 0, l;
	while (i < N/2)
	{
		for (l = 0; l < M/2; l++)
		{
			if (random = rand() % 100 < ast_number)
				*(arr[i] + l) = '*';
		}
		i++;
	}
}

void setMatrix(char(*arr)[M])
{
	int i = 0, l;
	while (i < N / 2)
	{
		for (l = 0; l < M / 2; l++)
		{
			*(arr[i] + M - 2 - l) = *(arr[i] + l);
			*(arr[N - 1 - i] + l) = *(arr[i] + l);
			*(arr[N - 1 - i] + M - 2 - l) = *(arr[i] + M - 2 - l);
		}
		i++;
	}
}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < N; i++)
	printf("%s\n", arr[i]);
}



