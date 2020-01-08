#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1024

int main()
{
	FILE* in;
	FILE* out;
	in = fopen("lab5.txt", "rt");
	out = fopen("lab5_Done.txt", "wt");
	if (in == NULL)
	{
		puts("File open erorr!");
		return 1;
	}

	time_t now;
	time(&now);
	srand(now);
	char inarr[SIZE] = { 0 };
	char outarr[SIZE] = { 0 };
	while (fgets(inarr, SIZE, in) != NULL)
	{
		if (inarr[strlen(inarr) - 1] == '\n')
			inarr[strlen(inarr) - 1] = '\0';
		printf("%s\n", randomWords(inarr, outarr));
		fprintf(out, "%s\n", randomWords(inarr, outarr));// записываю получившийся текст в файл
	}
	fcloseall();
	return 0;
}