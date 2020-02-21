#define _CRT_SECURE_NO_WARNINGS
#include "task3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 256

int main()
{
	srand(time(NULL));

	char instr[SIZE];
	char outstr[SIZE];

	FILE* fp_in = fopen("FILE.txt", "r");

	if (!fp_in)
	{
		puts("Error: file is not found");
		return 1;
	}

	FILE* fp_out = fopen("FILE_out.txt", "w");

	for (; ; )
	{
		if (fgets(instr, SIZE, fp_in) == NULL)
			break;

		mixLine(instr, outstr);
		fputs(outstr, fp_out);
		fputs("\n", fp_out);
	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}