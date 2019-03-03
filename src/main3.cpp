#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"
#define N 32
#define M 256

int main()

{
	srand(time(NULL));
	int count = 0;
	char instr[N][M] = { NULL }; 
	char outstr[M] = { NULL }; 
	FILE *fpRead, *fpWrite;
	fpRead = fopen("Text1.txt", "r");
	fpWrite = fopen("Text2.txt", "w");

	if (fpRead == NULL)
	{
		puts("Error! File Text1.txt not found!");
		return 1;
	}

	if (fpWrite == NULL)
	{
		puts("ERROR! File Text2.txt not found!");
		return 1;
	}

	while (count < N && !feof(fpRead))
	{
		fgets(instr[count], M, fpRead);
		fprintf(fpWrite, "%s\n", mixLine(instr[count], outstr));
		count++;
	}

	fclose(fpRead);
	fclose(fpWrite);
	return 0;

}