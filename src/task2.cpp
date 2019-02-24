#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 40
#define M 50
#define ST '*'

void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
}
void fillMatrix(char(*arr)[M])
{
	srand(time(NULL));
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < M / 2; j++)
		{
			if (rand() % 2 == 1)
				arr[i][j] = ST;
		}
}
void setMatrix(char(*arr)[M])
{
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < M / 2; j++)
		{
			if (arr[i][j] == ST)
			{
				arr[i][M - 1 - j] = ST;
				arr[N - 1 - i][M - 1 - j] = ST;
				arr[N - 1 - i][j] = ST;
			}
		}
}
void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			putchar(arr[i][j]);
		putchar('\n');
	}
}