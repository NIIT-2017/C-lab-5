#include <stdio.h>
#include "task1.h"
#define N 256

int main()
{
	char in[N] = { 0 };
	char out[N] = { 0 };

	FILE *fp;
	fp = fopen("in.txt", "r");
	if (fp == NULL)
		printf("File not found!");

	while (fgets(in, N, fp) != NULL)
		puts(randomWords(in, out));

	return 0;
}