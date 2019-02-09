#include <stdio.h>
#include <Windows.h>
#include "task2.h"
#define N 30
#define M 50

int main()
{
	char arr[N][M] = { 0 };

	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		system("cls");
		printMatrix(arr);
		Sleep(1000);
	}
	return 0;
}