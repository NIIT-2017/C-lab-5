#include <stdio.h>
#include "task1.h"
#define N 100

int main()
{
	char in[N] = { 0 }, out[N] = { 0 };
	printf("Enter a string:");
	fgets(in, N, stdin);
	puts(randomWords(in, out));
	return 0;
}