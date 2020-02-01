//Clab5 task2

#include "task2.h"

void clearMatrix(char(*arr)[M])				// заполнение двумерного массива(матрицы) пробелами
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
	}
}

void fillMatrix(char(*arr)[M])			// заполнение верхнего левого квадранта матрицы звездочками
{
	time_t now;
	time(&now);
	srand(now);
	int r = 2;

	for (int k = 0; k < M/2; k++)
	{
		for (int m = 0; m < M / 2; m++)
		{
			int choose = rand() % (r + 1);
			if (choose == 0)
				arr[k][m] = '*';

			else
				arr[k][m] = ' ';
		}
	}
}

void setMatrix(char(*arr)[M])		// копирование элементов в другие области матрицы
{
	for (int str = 0; str < M / 2; str++)
	{
		for (int sym = 0; sym < M / 2; sym++)
		{
			if (arr[str][sym] == '*')
				arr[str][M-sym-1] = '*';
			
		}
	}
	
	int f_str = 0;

	for (int l_str = M - 1; l_str >= M / 2; l_str--)
	{
		for (int sym = 0; sym < M-1; sym++)
		{
			if (arr[f_str][sym] == '*')
				arr[l_str][sym] = '*';
		}

		f_str++;
	}
}

void printMatrix(char(*arr)[M])		// печать матрицы
{
	system("cls");

	for (int str = 0; str < M; str++)
	{
		for (int sym = 0; sym < M; sym++)
		printf("%c", arr[str][sym]);
		putchar('\n');
	}


}