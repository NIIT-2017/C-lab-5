#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define M 60


void clearMatrix(char(*arr)[M])		// clear
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
	}
}

void fillMatrix(char(*arr)[M])		 // fill upper left angle
{
	int buf;
	for (int i = 0; i <= (M/2-1); i++)
	{
		for (int j = 0; j <= (M / 2 - 1); j++)
		{
			buf = rand() % 6;
			if (buf==1)
				arr[i][j] = 219;
		}
	}
}

void setMatrix(char(*arr)[M])		
{
	// copy to right angle
	for (int i = 0; i <= (M/2-1); i++)
	{
		
		for (int j = M / 2, q = M / 2 - 1; j < M; j++, q--)
		{
			arr[i][j] = arr[i][q];
		}
	}
	// copy to down part

	for (int i = (M / 2), q = (M / 2-1); i < M; i++,q--)
	{
		for (int j = 0; j < M; j++)
			arr[i][j] = arr[q][j];
	}
}

void printMatrix(char(*arr)[M])		
{
	system("cls");					//clear screen

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c", arr[i][j]);
			if (j == (M - 1))
				putchar('\n');
		}
	}
}