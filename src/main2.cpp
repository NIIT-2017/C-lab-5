/*
Решение задачи протекает в виде следующей последовательности шагов:

Очистка массива (заполнение пробелами)	clearMatrix
Формирование случайным образом верхнего левого квадранта (из символов) fillMatrix
Копирование символов в другие квадранты массива	setMatrix
Очистка экрана
Вывод массива на экран (построчно)	printMatrix
Временная задержка
Переход к шагу 1.
*/
#include "task2.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

int main()
{

	char arr[M][M] = { NULL };
	srand(time(0));
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		Sleep(550);
		setMatrix(arr);
		system("cls");
		printMatrix(arr);
		Sleep(500);
	}
	return 0;
}