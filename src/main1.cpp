#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include "task1.h"
#include <time.h>
#include <stdlib.h>
#define sLMax 201 // max length of string

int main()
{
	char in[sLMax] = {0};
	char out[sLMax];

	printf("Enter the string you want to randomize (no more than %d characters):\n", sLMax-1);
	fgets(in, sLMax, stdin);
	
	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';

	srand(time(0));
	printf("old string: \"%s\"\n", in);
	printf("new string: \"%s\"\n", randomWords(in, out));
	return 0;
}
