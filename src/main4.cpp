#define _CRT_SECURE_NO_WARNINGS
#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 256

int main()
{
	srand(time(NULL));

	char in[SIZE];
	char out[SIZE];

	FILE* fp_in = fopen("FILE.txt", "r");

	if (!fp_in)
	{
		puts("Error: file is not found");
		return 1;
	}

	FILE* fp_out = fopen("FILE_out.txt", "w");

	while (fgets(in, SIZE, fp_in) != NULL)
	{
		if(in[strlen(in) - 1] == '\n')
		{
			in[strlen(in) - 1] = '\0';
		}
		randomWords(in, out);
		fputs(out, fp_out);
		fputs("\n", fp_out);
	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;

}
