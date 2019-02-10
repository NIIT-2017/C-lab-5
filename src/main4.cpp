#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task1.h"
#include<string.h>
#define N 256

int main()
{
	char in[N] = { 0 }, out[N] = { 0 };
	FILE *fp, *fr;
	fp = fopen("222.txt", "r");
	if (fp == NULL)
	{
		puts("File error!\n");
		return 1;
	}
	fr = fopen("222_result.txt", "w");
	if (fr == NULL)
	{
		puts("File error!\n");
		return 2;
	}
	while ((fgets(in, N, fp) != NULL))
	{
		fputs(randomWords(in, out), fr);
		fputs("\n", fr);
	}
	fclose(fp);
	fclose(fr);
	return 0;
}