#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task1.h"

int main()
{
	char instr[256], outstr[256];
	char filename[] = "input.txt";
	FILE *fp;
	if ((fp = fopen(filename, "rt")) == NULL)
	{
		printf("file open error\n");
		return 0;
	}
	while (fgets(instr, 256, fp) != NULL)
		printf("%s\n", randomWords(instr, outstr));

	return 0;
}