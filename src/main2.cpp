#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task2.h"
#define M 60

int main()
{
	char arr[M][M];
	srand(time(NULL));
	int a = 0;
	while (a<=100)
	{
		 clearMatrix(arr);
		 fillMatrix(arr);
		 setMatrix(arr);
		 printMatrix(arr);

		unsigned int retTime = time(0) + 1;		// wait 1 sec
		while (time(0) < retTime);
		a++;
	}
	return 0;
}

