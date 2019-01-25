#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task1.h"

int main()
{
	printf("Enter a string:\n");
	char in[SIZE1] = {0};
	fgets(in, SIZE1, stdin);
	char out[SIZE1] = { 0 };
	srand(time(0));
	randomWords(in, out);
	puts(out);

	return 0;
}