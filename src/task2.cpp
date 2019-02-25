#include "task2.h"
#include <stdio.h>
#include <stdlib.h>
void setMatrix(char(*arr)[M])// - копирование элементов в другие области матрицы
{
	int i = 0, j = 0;
	for (i = 0; i < M/2; i++)//копирование в правый верхний квадрат
	{
		for (j = 0; j < M / 2; j++)
			arr[i][M - 1 - j] = arr[i][j];
	}
	for (i = 0; i < M/2; i++)//копирование верхней части в нижнюю
	{
		for (j = 0; j < M; j++)
			arr[M - 1 - i][j] = arr[i][j];
	}
}
void clearMatrix(char(*arr)[M])// - заполнение двумерного массива(матрицы) пробелами
{
	for (int i = 0; i < M/2; i++)
	{
		for (int j = 0; j < M/2; j++)
			arr[i][j] = ' ';
	}
	setMatrix(arr);
}

void fillMatrix(char(*arr)[M])// - заполнение верхнего левого квадранта матрицы звездочками
{
	int flag = 0;
	for (int i = 0; i < M/2; i++)
	{
		for (int j = 0; j < M/2; j++)
		{

			flag = rand() % 10;
			if (flag%2 == 0)
				arr[i][j] = '*';
			else
				arr[i][j] = ' ';
		}
	}
}

void printMatrix(char(*arr)[M])// - печать матрицы
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j <  M; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
}
