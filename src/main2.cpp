#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "task2.h"
#include <time.h>

void delay(int ms)
{
	int c = clock() + ms;
	while (clock() < c);
}

void screenClear()
{
	for (int i = 0; i < 25; i++)
	{
		printf("\n");
	}
}

int main()
{
	char arr[N][M];
	char (*a)[M] = arr;
	while(1)
	{
		clearMatrix(a); //заполнение двумерного массива(матрицы) пробелами

		fillMatrix(a);	//заполнение верхнего левого квадранта матрицы звездочками

		setMatrix(a);	//копирование элементов в другие области матрицы
		screenClear();
		printMatrix(a); //печать матрицы

		delay(2500);
		
	}

	 
	return 0;
}