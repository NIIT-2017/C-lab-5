#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "task2.h"
#define RATIO 7  //увеличивая или уменьшая RATIO мы можем увеличивать или уменьшать (соответственно) встречаемость звездочек
void clearMatrix(char(*arr)[M]) // заполнение матрицы пробелами
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
}
void fillMatrix(char(*arr)[M]) // заполнение первого квадранта звездочками
{
	for (int i = 0; i < (N / 2); i++)
		for (int j = 0; j <( M / 2); j++)
			if (rand() % RATIO == 0)
				arr[i][j] = '*';
}
void setMatrix(char(*arr)[M])
{
	for (int i = 0; i < (N / 2); i++) 
		for (int j = 0; j < (M / 2); j++)
			arr[i][M - 1 - j] = arr[i][j]; // копирование символов в правый верхний квадрант
	for (int i = 0; i < (N / 2); i++)
		for (int j = 0; j < M; j++)
			arr[N - 1 - i][j] = arr[i][j]; // копирование элементов в оставшуюся часть матрицы
}
void printMatrix(char(*arr)[M])
{
	system("cls"); // чистим содержимое экрана
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			putchar(arr[i][j]);
		putchar('\n');
	}
}