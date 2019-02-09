#include <stdio.h>
#include "task1.h"
#define N 256

int main()
{
	char in[N] = { 0 };
	char out[N] = { 0 };

	printf("Enter a string:\n");
	fgets(in, N, stdin);

	printf("%s", randomWords(in, out));
	return 0;
}