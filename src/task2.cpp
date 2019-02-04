#include <stdio.h>
#include <stdlib.h>
#include "task2.h"

#define A 6


void clearMatrix(char(*arr)[M])
{
	int i, j;
	for (i = 0; i <N; i++)
	{
		for (j = 0; j <M; j++)
			arr[i][j] = ' ';
	}
}

void fillMatrix(char(*arr)[M])
{
	int i, j, rnd = 0;
	for (i = 0; i < (N/2); i++)
	{
		for (j = 0; j < (M / 2); j++)
		{
			rnd = rand() % A;
			if (rnd == 0)
				arr[i][j] = '*';
		}
	}
}

void setMatrix(char(*arr)[M])
{
	int i, j;
	for (i =0; i<(N/2); i++)
		for (j = 0; j < (M / 2); j++)
		{
			if (arr[i][j] == '*')
				arr[i][(M-1) - j] =arr[(N-1)-i][j]=arr[(N-1)-i][(M-1)-j] = arr[i][j];
		}
}

void printMatrix(char(*arr)[M])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			putchar(arr[i][j]);
		putchar('\n');
	}
}