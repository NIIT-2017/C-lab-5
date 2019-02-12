#include "task2.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void clearMatrix(char(*arr)[M])	//заполнение двумерного массива(матрицы) пробелами
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = ' ';
			if (j == M - 1)
			{
				arr[i][j] = '\0';
			}
		}
	}
}
void fillMatrix(char(*arr)[M])	//заполнение верхнего левого квадранта матрицы звездочками
{
	srand(time(NULL));
	for (int i = 0; i < N/2; i++)
	{
		for (int j = 0; j < M/2; j++)
		{
			int a = rand() % 2;
			if (a == 0)
				arr[i][j] = '*'; // *
			if (a == 1)
				arr[i][j] = ' '; // пробел
			if(j==0)
				arr[i][j] = ' ';
		}
	}

}
void setMatrix(char(*arr)[M])	//копирование элементов в другие области матрицы
{
	//3 квадрант+
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = (M / 2); j < M - 1; j++)
		{
			arr[i][j] = arr[i][M - j - 1];
		}
	}
	//4 квадрант+
	for (int i = (N/2); i < N; i++)
	{
		for (int j = (M/2); j < M-1; j++)
		{
			arr[i][j] = arr[N-i-1][M-j-1];
		}
	}

	
	//2 квадрант
	for (int i = N/2; i < N; i++)
	{
		for (int j = 1; j < M/2; j++)
		{
		arr[i][j] = arr[i][M - j - 1];
		}
	}
}
void printMatrix(char(*arr)[M])	//печать матрицы
{
	for (int i = 0; i < N; i++)
	{
		printf("      %s       \n", arr[i]);
	}
}