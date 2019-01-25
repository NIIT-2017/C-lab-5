#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task2.h"

void clearMatrix(char(*arr)[M])//заполнение двумерного массива(матрицы) пробелами
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void fillMatrix(char(*arr)[M]) //заполнение верхнего левого квадранта матрицы звездочками
{
	for (int i = 0; i < (M/2); i++)
	{
		for (int j = 0; j < (M/2); j++)
		{
			int temp = rand() % 2;
			arr[i][j] = (temp) ? (' ') : ('*');
		}
	}
}
void setMatrix(char(*arr)[M]) //копирование элементов в другие области матрицы
{
	for (int i = 0; i < (M / 2); i++)//заполняем верхний правый квадрат
	{
		for (int j = (M / 2), k = ((M / 2) - 1); j < M, k >= 0; j++, k--)
		{
			arr[i][j] = arr[i][k];
		}
	}
	
	for (int i = (M / 2), k = ((M / 2) - 1); i < M, k >= 0; i++, k--)//заполняем нижний левый квадрат
	{
		for (int j = 0; j < (M / 2); j++)
		{
			arr[i][j] = arr[k][j];
		}
	}

	for (int i = (M / 2), k = ((M / 2) - 1); i < M, k >= 0; i++, k--)//заполняем нижний правый квадрат
	{
		for (int j = (M / 2), n = ((M / 2) - 1); j < M, n >= 0; j++, n--)
		{
			arr[i][j] = arr[k][n];
		}
	}
}

void printMatrix(char(*arr)[M]) //печать матрицы
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
//	printf("\n");
}