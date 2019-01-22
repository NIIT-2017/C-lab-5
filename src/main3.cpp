/*
   Написать программу, переставляющую случайным образом симво-
   лы каждого слова каждой строки текстового файла, кроме первого
   и последнего, то есть начало и конец слова меняться не должны.

   Write a program that randomly rearranges the characters of each word
   in each line of the text file, except the first and last,
   the beginning and the end of a word should not change.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"

int main()
{
	char str_in[S] = { '\0' };
	char str_out[S] = { '\0' };

	srand(time(NULL));

	FILE *f_in = fopen("str_in.txt", "r");
	if (f_in == NULL)
		puts("Can not find or open file!!!");

	FILE *f_out = fopen("str_out.txt", "w");
	if (f_out == NULL)
		puts("Error!!!");

	while (fgets(str_in, S, f_in) != NULL)
		fprintf(f_out, "%s\n", mixLine(str_in, str_out));

	fclose(f_in);
	fclose(f_out);

	return 0;
}