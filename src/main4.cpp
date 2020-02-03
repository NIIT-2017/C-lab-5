#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"
#define MAX_LEN 1024

void finishLine(char* line);

int main()
{

	FILE* in;
	in = fopen("task4.txt", "r");

	if (in == NULL)
	{
		puts("File open error!");
		return 1;
	}

	char instr[MAX_LEN];
	char outstr[MAX_LEN];

	while (fgets(instr, SIZE, in) != NULL)
	{
		finishLine(instr);
		printf("%s\n", instr);
		printf("%s\n", randomWords(instr, outstr));
		printf("\n");
	}
	fclose(in);

	return 0;
}

void finishLine(char* line)
{
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
}