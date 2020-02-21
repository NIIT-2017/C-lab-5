#define _CRT_SECURE_NO_WARNINGS
#include "task1.h"
#include <stdio.h>
#include <string.h>

#define SIZE 256

char* randomWords(char* in, char* out);

int main()
{	
	char in[SIZE] = { 0 };
	char out[SIZE] = { 0 };

	printf("enter the string\n");
	fgets(in, SIZE, stdin);
	if (in[strlen(in) - 1] == '\n')
	{
		in[strlen(in) - 1] = 0;
	}

	printf(randomWords(in, out));
	
	return 0;
}
