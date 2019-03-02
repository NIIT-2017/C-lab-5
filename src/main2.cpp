//Ќаписать программу Ф алейдоскопФ, вывод€щую на экран изображение, составленное из симметрично расположенных звездочек Т*Т.
//»зображение формируетс€ в двумерном символьном массиве, в одной его части и симметрично копируетс€ в остальные его части.

#define _CRT_SECURE_NO_WARNINGS
#include "task2.h"

int main() {

	char arr[N][M] = { '\0' };

	do {
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		system("cls");
		printMatrix(arr);
		Sleep(1000);
	} while (1);
	return 0;
}