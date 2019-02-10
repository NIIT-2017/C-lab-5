#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task2.h"
#define COLS 76
#define ROWS 24

int main()
{
	char arr[ROWS][COLS];
	
	srand(time(0));

	while (1)
	{
		clearMatrix(arr); // filling the matrix with spaces
		fillMatrix(arr); // filling upper left quadrant with stars
		setMatrix(arr); // copy symbols to other parts of the matrix

		system("cls"); // clear screen
		printMatrix(arr); //print all matrix
		clock_t t = clock();
		while (clock() < t + 10 * CLOCKS_PER_SEC);

	}

	return 0;
}