#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

void finishLine(char* line);

int main()
{
	FILE* in;
	in = fopen("task3.txt", "r");
	if (in == NULL)
	{
		puts("File open error!");
		return 1;
	}
	
	int count = 0;
	char instr[MAX_ROWS][MAX_ROW_SIZE];
	char outstr[MAX_ROWS][MAX_ROW_SIZE];

	while (fgets(instr[count], MAX_ROW_SIZE, in) != NULL)
	{
		finishLine(instr[count]);
		printf("%s\n", instr[count]);
		printf("%s\n", mixLine(instr[count], outstr[count]));
		printf("\n");
		count++;
	}
	fclose(in);
	
	return 0;
}

void finishLine(char* line)
{
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
}