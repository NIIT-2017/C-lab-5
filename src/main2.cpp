#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task2.h"

void clrscr(void);

int main()
{

	char arr[N][M];
	clearMatrix(arr);
	int i, j;

	time_t now;
	time(&now);
	srand((unsigned int)now);
	rand();


	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		clrscr();
		printMatrix(arr);
		clock_t begin = clock();
		//while (clock() < begin + CLOCKS_PER_SEC / 20);
		while (clock() < begin + CLOCKS_PER_SEC);
	}

	return 0;
}

void clrscr(void)
{
	char a[80];
	printf("\033[2J"); /* Clear the entire screen. */
	printf("\033[0;0f"); /* Move cursor to the top left hand corne*/
	
}