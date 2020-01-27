#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"task3.h"

int main()
{
	FILE*fp;
	char instr[LINE][SIZE];
	char outstr[LINE][SIZE] = { 0 };
	int i = 0; //for account entered lines, so as not to go beyond the bounds of array "in"

	if ((fp = fopen("task3.txt", "a+")) == NULL)
	{
		puts("File open ERROR!");
		return 1;
	}

	while (i < LINE && fgets(instr[i], SIZE, fp) != NULL)
	{
		if (instr[i][strlen(instr[i]) - 1] == '\n')
			instr[i][strlen(instr[i]) - 1] = '\0';

		mixLine(instr[i], outstr[i]);
		i++;
	}

	for (int j = 0; j <= i; j++)
		fprintf(fp, "\n%s", outstr[j]);

	if (fclose(fp) != 0)
		puts("Error closing the file!");

	return 0;
}