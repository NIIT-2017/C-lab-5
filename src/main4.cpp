#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#define SIZE 256

int main()
{
	char in[SIZE];
	char out[SIZE];
	FILE* fp;
	fp = fopen("file.txt", "rw");
	if (fp == NULL)
	{
		puts("Erorr");
		return 1;
	}
	while (fgets(in, SIZE, fp) != 0 && *in != '\n')
	{
		if (in[strlen(in) - 1] == '\n')
		{
			in[strlen(in) - 1] = 0;
		}
	}
	fclose(fp);
	printf("%s", randomWords(in, out));
	printf("done");
	return 0;
}
