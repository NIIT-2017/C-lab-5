#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define size_str 255
#include "task1.h"
void CleanMass(char *in)//clean massiv
{
	for (int i = 0; in[i] != '\0'; i++)
		in[i] = '\0';
}

int main()
{
	char instr[size_str] = { NULL };
	char outstr[size_str] = { NULL };
	srand(time(0));
	FILE *fp;
	fp = fopen("text.txt", "r");
	if (fp == NULL)
	{
		puts("File not found");
		return 1;
	}
	while (fgets(instr, 100, fp) != NULL)
	{

		randomWords(instr, outstr);
		printf("%s", outstr);
		CleanMass(instr);
		CleanMass(outstr);
	}
	fclose(fp);
	return 0;
}