/*
Написать программу, переставляющую случайным образом символы каждого слова каждой строки текстового файла, 
кроме первого и последнего, то есть начало и конец слова меняться не должны.

Программа открывает существующий тектстовый файл и читает его построчно. 
Для каждой строки выполняется разбивка на слова и независимая обработка каждого слова
*/
#include "task3.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	char instr[255] = { NULL };
	char outstr[255] = { NULL };
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
		
		mixLine(instr, outstr);
		printf("%s", outstr);
		CleanMass(instr);
		CleanMass(outstr);
	}
	fclose(fp);
	return 0;
}