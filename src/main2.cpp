#include "task2.h"
#include <stdio.h>
#include <time.h>


int main()
{
	char arr[M][M];
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		unsigned int retTime = time(0) + 1;
		while (time(0) < retTime);
		puts(" ");
	}
}