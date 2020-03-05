#include <stdio.h>
#include <string.h>
#include "task1.h"
int main()
{
	char in[256];
	char out[256];
	printf("Enter a string of words\n");
	fgets(in, 256, stdin);
	if (*in != 0 && in[strlen(in) - 1] == '\n')// if 1 elem is not=0
	{
		in[strlen(in) - 1] = '\0';
	}
	randomWords(in, out);
	puts(out);
	return 0;
}