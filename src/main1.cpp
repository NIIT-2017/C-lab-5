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

	printf("Enter a string:\n");
	fgets(in, N, stdin);

	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';

	//printf("%s", in);
	randomWords(in, out);
	printf("%s", out);

	return 0;
}