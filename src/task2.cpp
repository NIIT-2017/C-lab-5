#include "task2.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
	}
}

void fillMatrix(char(*arr)[M])
{
	for (int i = 0; i < M / 2; i++)
	{
		for (int j = 0; j < M / 2; j++)
		{
			if (rand() % 2 == 1)
				arr[i][j] = '*';
		}
	}
}

void setMatrix(char(*arr)[M])
{
	for (int i = 0; i <= M / 2; i++)
	{
		for (int j = M / 2, countJ = 1; j < M && countJ < M; j++, countJ += 2)
		{
			arr[i][j] = arr[i][j - countJ];
		}
	}
	for (int i = M / 2, countI = 1; i < M && countI < M; i++, countI += 2)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = arr[i - countI][j];
		}
	}
}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c", arr[i][j]);
		}
		putchar('\n');
	}
}