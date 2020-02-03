#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"task2.h"

void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < N; i++) //array flooding ' '
	   for (int j = 0; j < M; j++)
		   arr[i][j] = ' ';
}

void fillMatrix(char(*arr)[M])
{
	char ch;
	srand(time(NULL));

	for (int i = 0; i < N / 2; i++)  //random array flooding
	  for (int j = 0; j < M / 2; j++)
	     if ((0 + rand() % (9 - 0 + 1)) % 3 == 0 ? ch = ' ' : ch = '*')
		     arr[i][j] = ch;
}

void setMatrix(char(*arr)[M])
{

  for (int i = 0; i < N / 2; i++)   //copying a quarter
	for (int j = 0; j < M / 2; j++)
	   if (arr[i][j] == '*')
		   arr[i][(M - 1) - j] = '*';

   for (int i = 0; i < N / 2; i++)  //copying a half
	 for (int j = 0; j < M; j++)
	    if (arr[i][j] == '*')
		    arr[(N - 1) - i][j] = '*';

}

void printMatrix(char(*arr)[M])
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c", arr[i][j]);
		}
		putchar('\n');
		clock_t begin = clock();
		while (clock() < begin + CLOCKS_PER_SEC); //time delay
	}
	putchar('\n');
}