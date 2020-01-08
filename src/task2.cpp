#include <stdio.h>
#include <stdlib.h>

#define M 20

//1 - Очистка массива (заполнение пробелами)
void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
}

//2 - Формирование случайным образом верхнего левого квадранта (из символов)
void fillMatrix(char(*arr)[M])
{
	int res = 0;
	for (int i = 0; i < M/2; i++)
		for (int j = 0; j < M / 2; j++)
		{
			res = rand() % 2;
			if (res == 1)
				arr[i][j] = '*';
		}
}

//3 - Копирование символов в другие квадранты массива
void setMatrix(char(*arr)[M])
{
	for (int i = 0; i < M / 2; i++)
		for (int j = M / 2; j < M; j++)
			arr[i][j] = arr[i][M - 1 - j];
	for (int i = M / 2; i < M; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = arr[M - 1 - i][j];
}

//4 - Вывод массива на экран
void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%c", arr[i][j]);
		putchar('\n');
	}
}
