#include <stdio.h>
#include <string.h>
#include "task2.h"
#define M 10
int main()

{
	char arr[M][M];
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		
	}
	return 0;
}