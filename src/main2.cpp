//Clab5 task2

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
		
		clock_t(begin) = clock();
		while (clock() < begin + 2 * CLOCKS_PER_SEC); //  CLOCKS_PER_SEC - универсально для всех систем, для Linux можно использовать 1000
	}

	return 0;
}