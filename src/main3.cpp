#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task3.h"
#include<string.h>
#define N 256

int main()
{
	char instr[N] = { 0 }, outstr[N] = { 0 };
	FILE *fp, *fr;
	fp = fopen("333.txt", "r");
	if (fp == NULL)
	{
		puts("File error!\n");
		return 1;
	}
	fr = fopen("333_result.txt", "w");
	if (fr == NULL)
	{
		puts("File error!\n");
		return 2;
	}
	while ((fgets(instr, N, fp) != NULL))
	{
		fputs(mixLine(instr, outstr), fr);
		fputs("\n", fr);
	}
	fclose(fp);
	fclose(fr);

	return 0;
}