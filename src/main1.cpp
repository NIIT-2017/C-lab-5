#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1024

int main()
{
	time_t now;
	time(&now);
	srand(now);
	char in[SIZE] = { 0 };
	char out[SIZE] = { 0 };
	printf("Please enter string\n");
	fgets(in, SIZE, stdin);
	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';
	printf("%s\n",randomWords(in, out));
	return 0;
}