#include <stdlib.h>
#include <stdio.h>
#define m05  M/2 
#define M 20

void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			*(*(arr + i) + j) = ' ';
	}
}

void fillMatrix(char(*arr)[M])
{
	int K =0.45*m05*m05;
	int i = 0;
	while (i < K)
	{
		int k = rand() % m05;
		int l = rand() % m05;
		if (*(*(arr + k) + l) == ' ')
		{
			*(*(arr + k) + l) = '*';
			i++;
		}
	}
}

void setMatrix(char(*arr)[M])
{
	for (int i = 0; i < m05; i++)
	{
	int y = M - 1 - i;
		for (int j = 0; j < m05; j++)
		{
			int x = M - 1 - j;
			*(*(arr + y)  + x)  =  *(*(arr + y) + j)  =  *(*(arr + i) + x)  =  *(*(arr + i) + j);
		}
	}

}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		printf("%c ",*(*(arr + i) + j));
		putchar('\n');
	}
}