#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "task2.h"
#include <cstdlib>



void clearMatrix(char(*arr)[M])
{
	int i = 0, j = 0;
	while (i < M)
	{
		for (j=0; j < M; j++)
			arr[i][j] = ' ';
		arr[i][j] = '\0';
		i++;
		j = 0;
	}
}

void fillMatrix(char(*arr)[M])
{
	int i = 0, j = 0, k = 0;
	for (i=0; i < M / 2; i++)
	{
		for(k=0; k < M / 2; k++)
		{
			j = rand() % (M/2);
			arr[i][j] = '*';
		}
		j = 0;
	}
}


void setMatrix(char(*arr)[M])
{
	int i = 0, j = 0, k = M-1;
	while (i < M / 2)
	{
		while (k >= M / 2)
		{
			arr[i][k] = arr[i][j];
			j++;
			k--;
		}
		i++;
		j = 0;
		k = M-1;
	}
	
	i = 0;
	while (k >= M/2)
	{
		for (j=0; j<M; j++)
			arr[k][j] = arr[i][j];
		k--;
		i++;
	}
}

void printMatrix(char(*arr)[M])
{
	int i = 0, j = 0;
	for (i=0; i < M; i++)
		{
		for (j=0; j < M; j++)
			{
				printf("%c", arr[i][j]);
				
			}
			printf("\n");
		}
	
	printf("\n");
	
}