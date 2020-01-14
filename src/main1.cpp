#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

void finishLine(char* line);

int main()
{
	char in[SIZE];
	char out[SIZE];

	fgets(in, SIZE, stdin);
	finishLine(in);

	printf("%s", randomWords(in, out));

	return 0;
}

void finishLine(char* line)
{
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
}