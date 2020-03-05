#include "task2.h"
#include <stdio.h>
#define M 25

int main()
{
	char arr[M][M];
	clearMatrix(arr);
	fillMatrix(arr);
	setMatrix(arr);
	printMatrix(arr);
	return 0;	
}