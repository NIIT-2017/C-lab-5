#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include "task2.h"

int main()
{
	char arr[M][M];
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		sleep(5);
	}
	return 0;
}

