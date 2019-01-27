#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include "task2.h"



int main(void)
{
	char buf[N][M];
	char (*arr)[M] = buf;
	
	for (int number = 0; number < 100; number++)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		Sleep(1000);
		system("cls");
	}
		
	getchar();
	return 0;
}