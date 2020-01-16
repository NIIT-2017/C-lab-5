#include "task2.h"


void clearMatrix(char(*arr)[M]) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
}

void fillMatrix(char(*arr)[M]) {
	srand(time(NULL));

	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < M / 2; j++)
		{
			if (rand() % 2)
				arr[i][j] = '*';
		}
}

void setMatrix(char(*arr)[M]) {
	for (int i = 0; i < (N / 2); i++)
		for (int j = 0; j < (M / 2); j++)
			arr[i + (N / 2)][j] = arr[i][j];
		
	for (int i = 0; i < (N / 2); i++)
		for (int j = 0; j < (M / 2); j++)
			arr[i][j + (M / 2)] = arr[i][j];
		
	for (int i = 0; i < (N / 2); i++)
		for (int j = 0; j < (M / 2); j++)
			arr[i + (N / 2)][j + (M / 2)] = arr[i][j];
		
}

void printMatrix(char(*arr)[M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%c ", arr[i][j]);

		printf("\n");
	}
}