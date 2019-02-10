#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task3.h"
#define N 50


int main()
{
	char instr[N] = { 0 };
	char outstr[N] = { 0 };

	srand(time(0));

	FILE *fp;
	FILE *fr;
	fp = fopen("random_lettersr.txt", "r");
	fr = fopen("random_lettersw.txt", "w");

	if (fp == NULL)
	{
		puts("File not found!");
		return 1;
	}

	if (fr == NULL)
	{
		puts("File not found!");
		return 1;
	}

	while (fgets(instr, N, fp) != NULL)
	{
		if (instr[strlen(instr) - 1] == '\n')
			instr[strlen(instr) - 1] = '\0';

		mixLine(instr, outstr);
		printf("%s\n", outstr);
		fprintf(fr, "%s\n", outstr);
	}

	fclose(fp);
	fclose(fr);
	return 0;
}