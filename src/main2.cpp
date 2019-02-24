/*Ќаписать программу Ф алейдоскопФ, вывод€щую на экран изобра-
   жение, составленное из симметрично расположенных звездочек Т*Т.
   »зображение формируетс€ в двумерном символьном массиве, в од-
   ной его части и симметрично копируетс€ в остальные его части.*/
#include "task2.h"
#include <stdio.h>
#include<time.h>
#include <stdlib.h>

int main()
{
	char arr[M][M];
	srand(time(NULL));
	int a = 0;
	while (a <= 100)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);

		unsigned int retTime = time(0) + 1;		
		while (time(0) < retTime);
		a++;
	}
	return 0;
}