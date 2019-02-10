#define COLS 76
#define ROWS 24
#include <stdio.h>
#include <stdlib.h>

void clearMatrix(char(*arr)[COLS]) // filling the matrix with spaces
{
	for (int i = 0;i < ROWS; i++) // column
	{
		for (int j = 0; j < COLS;j++) // string
			arr[i][j] = ' ';
	}
}

void fillMatrix(char(*arr)[COLS]) // filling upper left quadrant with stars
{
	int chance = 0;
	for (int i = 0;i < ROWS / 2; i++) // column
	{
		for (int j = 0; j < COLS / 2;j++) // string
		{
			chance = rand() % 2;
			if (chance == 0)
				arr[i][j] = '*';
		}
	}
}
void setMatrix(char(*arr)[COLS]) // copy symbols to other parts of the matrix
{
	
	for (int i = 0;i < ROWS / 2; i++) // copy to the uuper right quadrant
	{
		for (int j = 0, k = COLS - 1; j < COLS / 2;j++, k--) 
		{
			arr[i][k] = arr[i][j];
		}
	}

	for (int i = 0, j = ROWS - 1;i < ROWS / 2; i++, j--) // copy to the bottom half of the matrix
	{
		for (int k = 0; k < COLS; k++) 
		{
			arr[j][k] = arr[i][k];
		}
	}
}

void printMatrix(char(*arr)[COLS]) //print all matrix
{
	for (int i = 0;i < ROWS; i++) //column
	{
		for (int j = 0; j < COLS;j++)//string
			printf("%c", arr[i][j]);
		printf("\n");
	}
}