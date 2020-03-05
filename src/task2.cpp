#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 25

void clearMatrix(char(*arr)[M]) //заполнение двумерного массива (матрицы) пробелами
{
	int i;
	int j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void fillMatrix(char(*arr)[M])//заполнение верхнего левого квадранта матрицы звездочками
{
	srand(time(NULL));
	int i;
	int j;
	int n = 0;
	n = M / 2;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < n; j = rand() % n + 1)
		{
			arr[i][j] = '*';
		}
	}
}
void setMatrix(char(*arr)[M])//копирование элементов в другие области матрицы
{
	int i;
	int j;
	int n = 0;
	n = M / 2; 
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr[M - 1 - i][j] = arr[i][j];
		}
	}
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr[i][M - 1 - j] = arr[i][j];
		}
	}
}
void printMatrix(char(*arr)[M]) //печать матрицы
{
	int i;
	int j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}
		