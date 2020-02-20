#include <stdio.h>
#include <string.h>
#include "task1.h"
#define SIZE 256

int main()
{
	char in[SIZE];
	char out[SIZE];
	printf("Enter a string: ");
	fgets(in, SIZE, stdin);
	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = 0;
	printf("Prepared string: %s", randomWords(in, out));
	return 0;
}