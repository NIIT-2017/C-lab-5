#define _CRT_SECURE_NO_WARNINGS
#define SIZE 256
#include "task1.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	srand(time(NULL));
	FILE *fp = NULL, *fo = NULL;
	char strin[SIZE] = { 0 }, strout[SIZE] = { 0 };
	fp = fopen("task4r.txt", "r");
	fo = fopen("task4w.txt", "w");
	if (fp == NULL)
	{
		printf("Can't open task4r.txt");
		return 1;
	}
	if (fo == NULL)
	{
		printf("Can't open task4w.txt");
		return 2;
	}
	while (!feof(fp))
	{
		fgets(strin, SIZE, fp);
		randomWords(strin, strout);
		fputs(strout, fo);
		fputc('\n', fo);
	}
	fclose(fp);
	fclose(fo);
	return 0;
}