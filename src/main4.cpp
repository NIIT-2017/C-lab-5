#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "task1.h"
//Написать программу, которая читает построчно текстовый файл и
//переставляет случайно слова в каждой строке
//Программа открывает существующий тектстовый файл и читает его построчно.
int main()
{
	FILE * fr = NULL, *fw = NULL;
	fr = fopen("1.txt", "r");
	if (!fr)//cheking of the file
	{
		printf("Cannot read file!\n");
		return 1;
	}
	fw = fopen("2.txt", "w");
	if (!fw)//cheking of the file
	{
		printf("Cannot write file!\n");
		return 2;
	}
	char in[SIZE1] = { 0 };
	char out[SIZE1] = { 0 };
	srand(time(0));
	while (!feof(fr))
	{
		fgets(in, SIZE1, fr);
		randomWords(in, out);
		fputs(out, fw);
		fputs("\n", fw);
	}
	fclose(fr);
	fclose(fw);
	return 0;
}