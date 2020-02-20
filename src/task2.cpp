#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"

void clearMatrix(char(*arr)[M])/* -заполнение двумерного массива(матрицы) пробелами*/
{
	for (int i = 0; i<M; i++)
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = ' ';
		}
}
void fillMatrix(char(*arr)[M])/* -заполнение верхнего левого квадранта матрицы звездочками*/
{
	srand(time(NULL));
	int p = 2;
	for (int i = 0; i < M / 2; i++)
		for (int j = 0; j < M / 2; j++)
		{
			int variant = rand() % (p + 1);
			switch(variant)
			{
			case 0:
				arr[i][j] = '*';
			break;
			case 1:
				arr[i][j] = ' ';
			break;
			}
		}
	
}
void setMatrix(char(*arr)[M])/* -копирование элементов в другие области матрицы*/
{
	for (int i = 0; i < M / 2; i++)
		for (int j = 0; j < M / 2; j++)
		{
			if (arr[i][j] == '*')
			{
				arr[i][M - 1 - j] = '*';
				arr[M - 1 - i][M - 1 - j] = '*';
				arr[M - 1 - i][j] = '*';
			}
		}
}
void printMatrix(char(*arr)[M])/* -печать матрицы*/
{
	system("cls");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			putchar(arr[i][j]);
		putchar('\n');
	}
}