#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "task3.h"
#define N 256

int main()
{
	char instr[N] = { 0 };
	char outstr[N] = { 0 };

	FILE *fp;
	fp = fopen("123.txt", "r");
	if (fp == NULL)
	{
		puts("File not found!");
		return 1;
	}

	while (fgets(instr, N, fp) != NULL)
		puts(mixLine(instr, outstr));

	fclose(fp);

	return 0;
}