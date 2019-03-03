#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"



int main()

{
	char arr[N][M];
	srand(time(NULL));
	
		clearMatrix(arr); 
		fillMatrix(arr); 
		setMatrix(arr); 
		printMatrix(arr); 
		clock_t t1 = clock();
		while (clock() - t1 < (CLOCKS_PER_SEC * 1)) // 1-sec-delay
			clock_t t1 = clock();

	
	putchar('\n');

	return 0;

}