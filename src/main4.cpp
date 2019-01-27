#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task1.h"


int main(void)
{
	char in[256];
	char out[256];

	FILE *fp;
	fp = fopen("111.txt", "r+");
	if (fp == NULL)
		puts("not found");

	fgets(in, 256, fp) != NULL;
	randomWords(in, out); 
	fputs("\n", fp);
	fputs(out, fp);
	fclose(fp);

	getchar();
	return 0;
}