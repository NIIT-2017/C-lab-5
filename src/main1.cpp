#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task1.h"
#define N 256



int main()
{
	char in[N] = { NULL };
	char out[N] = { NULL };
	printf("Please, enter any string to randomise its words!\n");
	fgets(in, N, stdin);
	putchar('\n');
	printf("%s", randomWords(in, out));

	return 0;
}

