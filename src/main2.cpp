#include <stdlib.h>
#include <time.h>
#include "task2.h"

int main()
{
	char arr[N][M];
	srand(time(NULL));
	while (1)
	{
		clearMatrix(arr); // заполнение матрицы пробелами
		fillMatrix(arr); // формирование левого верхнего квадранта
		setMatrix(arr); // заполнение остальной части матрицы звездочками
		printMatrix(arr); // вывод матрицы на экран
		clock_t t1 = clock();
		while (clock() - t1 < (CLOCKS_PER_SEC * 2)) // задержка в 2 секунды
			clock_t t1 = clock();
	}
	return 0;
}