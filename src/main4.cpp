/*
	Ќаписать программу, котора€ читает построчно текстовый файл и
	переставл€ет случайно слова в каждой строке.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task1.h"


int main()
{
	char str_in[S] = { '\0' };
	char str_out[S] = { '\0' };

	srand(time(0));

	FILE *file_in = fopen("str_in.txt", "r");
	if (file_in == NULL)
		puts("Can not find or open file!!!");

	FILE *file_out = fopen("str_out.txt", "w");
	if (file_out == NULL)
		puts("Error!!!");

	while (fgets(str_in, S, file_in) != NULL)
		fprintf(file_out, "%s\n", randomWords(str_in, str_out));

	fclose(file_in);
	fclose(file_out);

	return 0;
}