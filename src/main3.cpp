#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"
#define SIZE 256

int main()
{
	char instr[SIZE] = { 0 };
	char outstr[SIZE] = { 0 };

	FILE* fp;
	fp = fopen("wind.txt", "rt");
	if (!fp)
	{
		puts("File error!");
		return 1;
	}
	
	while (fgets(instr, SIZE, fp))
	{

		puts(mixLine(instr, outstr));

	}
	
	fclose(fp);
	
	return 0;
}