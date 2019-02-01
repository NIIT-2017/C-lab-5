#include "task2.h"
#include <stdio.h>
#include <Windows.h>


int main()
{
	char arr[M][M];
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		Sleep(1000);
		puts(" ");
	}
}