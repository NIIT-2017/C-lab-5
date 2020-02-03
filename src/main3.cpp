#include "task3.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 1024

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
	char inarr[N] = { 0 };
	char outarr[N] = { 0 };
	int i = 0;
	while (fgets(inarr, N, in) != NULL)
	{
		if (inarr[strlen(inarr) - 1] == '\n')
			inarr[strlen(inarr) - 1] = '\0';
		printf("%s\n", mixLine(inarr, outarr));
		fprintf(out, "%s\n", mixLine(inarr, outarr));// записываю получившийся текст в файл
	}
	fcloseall();
	return 0;
}