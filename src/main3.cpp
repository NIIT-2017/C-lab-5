#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

int main()
{
	FILE * fr = NULL, *fw = NULL;
	fr = fopen("1.txt", "r");
	if (!fr)//cheking of the file for reading
	{
		printf("Cannot read file!\n");
		return 1;
	}
	fw = fopen("2.txt", "w");
	if (!fw)//cheking of the file for writing
	{
		printf("Cannot write file!\n");
		return 2;
	}
	char instr[SIZE] = { 0 };
	char outstr[SIZE] = { 0 };
	srand(time(0));
	while (!feof(fr))
	{
		fgets(instr, SIZE, fr);
		mixLine(instr, outstr);
		fputs(outstr, fw);
		fputs("\n", fw);
	}
	fclose(fr);
	fclose(fw);


	return 0;
}
/* //checking block
int main()
{
	
	char instr[SIZE] = { "1234567 Violet is a very beautiful flower"};
	char outstr[SIZE] = { 0 };
	srand(time(0));
	mixLine(instr, outstr);
	puts(outstr);
	return 0;
}
*/