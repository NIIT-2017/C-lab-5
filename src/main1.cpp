#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "task1.h"

int main()
{
	char str[256];
	char out[256];
	printf("Enter a string\n");
	fgets(str, 256, stdin);
	randomWords(str, out);

	printf("%s", out);
	return 0;
}