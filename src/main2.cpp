#define _CRT_SECURE_NO_WARNINGS
#include "task2.h"

int main()
{
	char arr[SIZE][SIZE];
	
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		system("cls");
		printMatrix(arr);

		//getchar();

		clock_t time = clock();
		while (clock() < time + CLOCKS_PER_SEC);
	}

	return 0;
}