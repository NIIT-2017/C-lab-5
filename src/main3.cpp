#define STR_SIZE 256															//предполагаемая максимальная длина строки в файле
#define _CRT_SECURE_NO_WARNINGS
#include "task3.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	char strIn[STR_SIZE] = { NULL }, strOut[STR_SIZE] = { NULL };
	FILE *fIn = NULL, *fOut = NULL;
	fIn = fopen("task3Read.txt", "r");
	if (fIn == NULL)
	{
		printf("Can't open file task3Read.txt");
		return 1;
	}
	fOut = fopen("task3Write.txt", "w");
	if (fIn == NULL)
	{
		printf("Can't open file task3Write.txt");
		return 2;
	}
	while (!feof(fIn))
	{
		fgets(strIn, STR_SIZE, fIn);
		mixLine(strIn, strOut);
		fputs(strOut, fOut);
		fputc('\n', fOut);
	}
	fclose(fIn);
	fclose(fOut);
	return 0;
}