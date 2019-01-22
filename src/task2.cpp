#include "task2.h"
#include <stdio.h>
#include <stdlib.h>  //rand()
#define SPACE ' '

void clearMatrix(char(*arr)[COLS]) // filling a two-dimensional array (matrix) with spaces
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			arr[i][j] = SPACE;
}

void fillMatrix(char(*arr)[COLS])  // filling the upper left quadrant of the matrix with '*' characters
{
	int squaresNumber = COLS * ROWS / 8;  // total characters '*' in one quarter
	int fillNumber = 0; // already inserted characters '*'
	int i = 0;
	int j = 0;

	while (fillNumber < squaresNumber)
	{
		i = rand() % (ROWS / 2);  // rows - Y-coordinates for '*'
		j = rand() % (COLS / 2);  // cols - X-coordinates for '*'
		if (arr[i][j] = SPACE)
		{
			arr[i][j] = '*';
			fillNumber++;
		}
	}
}

void setMatrix(char(*arr)[COLS])  // copying elements to other areas of the matrix
{
	int rows = (ROWS / 2);
	int cols = (COLS / 2);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[ROWS - 1 - i][j] = arr[i][j];
			arr[i][COLS - 1 - j] = arr[i][j];
			arr[ROWS - 1 - i][COLS - 1 - j] = arr[i][j];
		}
	}
}

void printMatrix(char(*arr)[COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			putchar(arr[i][j]);
		putchar('\n');
	}
}

void clearScreen(void)
{
	printf("\033[2J"); // Clear the entire screen.
	printf("\033[0;0f"); // Move cursor to the top left hand corner
}