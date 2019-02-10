#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 6
#define M 10

void clearMatrix(char(*arr)[M]) /*- заполнение двумерного массива(матрицы) пробелами*/
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
}
void fillMatrix(char(*arr)[M]) /*- заполнение верхнего левого квадранта матрицы звездочками*/
{
	int x = 0, y = 0, k = 1;
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < M / 2; j++)
		while (k<= (M*N) / 8)
		{
			x = rand() % (N/2-1);
			y = rand() % (M/2-1);
			if (arr[x][y] != '*')
				arr[x][y] = '*';
			k++;
		}
}
void setMatrix(char(*arr)[M]) /* копирование элементов в другие области матрицы*/
{
	for (int i = 0; i < N/2; i++)
		for (int b = M-1, j = 0; b >= M / 2; j++, b--)
			arr[i][b] = arr[i][j];
	for (int a = N-1, i = 0; a >= N / 2; i++, a--)
		for (int j = M-1; j > M/2; j--)
			arr[a][j] = arr[i][j];
	for (int i = N-1; i >= N / 2; i--)
		for (int b = 0, j = M-1; b < M/2; j--, b++)
			arr[i][b] = arr[i][j];
}
void printMatrix(char(*arr)[M])/*печать матрицы*/
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}