#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "task3.h"


int main(void)
{
	char instr[256];
	char outstr[256];
	
	FILE *fp;
	fp = fopen("111.txt", "r");
	if (fp == NULL)
		puts("not found");

	while (fgets(instr, 256, fp) != NULL)
		mixLine(instr, outstr), puts(outstr);

	

	fclose(fp);

	getchar();
	return 0;
}