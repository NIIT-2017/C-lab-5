//Clab5 task 4

/* Ќаписать программу, котора€ читает построчно текстовый файл и переставл€ет случайно слова в каждой строке*/

#include "task1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	char in[SIZE];
	char out[SIZE];
	
	FILE* fp_in = fopen("FILE.txt", "r");
	FILE* fp_out = fopen("FILE_out.txt", "w");
	
	for (; ; )
	{
		if (fgets(in, SIZE, fp_in) == NULL)
			break;
		randomWords(in, out);
		fputs(out, fp_out);
		fputs("\n", fp_out);
	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}