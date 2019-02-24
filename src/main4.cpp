/*Ќаписать программу, котора€ читает построчно текстовый файл и
    переставл€ет случайно слова в каждой строке*/

#include <stdio.h>
#include "task1.h"
#include <string.h>
#define N 256

int main()
{
	char in[N] = { 0 };
	char out[N] = { 0 };
	int count = 0;

	FILE *f_In;
	f_In = fopen("1.txt", "r");

	FILE *f_Out;
	f_Out = fopen("2.txt", "w");

	while (count < N && fgets(in, N, f_In) != 0)
	{
		randomWords(in, out);
		fputs(out, f_Out);
		fputs("\n", f_Out);
		for (int i = 0; i < N; i++)
		{
			in[i] = '\0';
			out[i] = '\0';
		}
		count++;
	}
	puts("Done!");
	fclose(f_In);
	fclose(f_Out);
	return 0;
}