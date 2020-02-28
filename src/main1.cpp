#include <stdio.h>
#include <string.h>
#include "task1.h"
#define SIZE 256

int main()
{
	char in[SIZE];
	char out[SIZE];
	printf("Input some string: \n");
	fgets(in, SIZE, stdin);
	if (in[strlen(in) - 1] == '\n')
	{
		in[strlen(in) - 1] = '\0';
	}
	randomWords(in, out);
	puts(out);
	return 0;
}
