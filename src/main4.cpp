#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task1.h"
#define N 256


int main()
{
	char in[N] = { 0 };
	char out[N] = { 0 };

	srand(time(0));

	FILE *fp;
	FILE *fr;
	fp = fopen("random_wordsr.txt", "r");
	fr = fopen("random_wordsw.txt", "w");

	if (fp == NULL)
	{
		puts("File not found!");
		return 1;
	}

	if (fr == NULL)
	{
		puts("File not found!");
		return 1;
	}

	while (fgets(in, N, fp) != NULL)
	{
		if (in[strlen(in) - 1] == '\n')
			in[strlen(in) - 1] = '\0';
		
		randomWords(in, out);
		printf("%s\n", out);
		fprintf(fr, "%s\n", out);
	}

	fclose(fp);
	fclose(fr);
	return 0;
}