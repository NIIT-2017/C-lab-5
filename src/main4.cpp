#include <stdio.h>
#include "task1.h"
#define N 32
#define M 128

int main()

{
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
		puts("Error! File 2.txt not found!");
		return 1;
	}

	while (count < N && !feof(fpRead))
	{
		fgets(instr[count], M, fpRead);
		fprintf(fpWrite, "%s\n", randomWords(instr[count], outstr));
		count++;
	}
	fclose(fpRead);
	fclose(fpWrite);

	return 0;

}