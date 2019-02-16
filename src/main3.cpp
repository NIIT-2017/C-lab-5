#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"
#define N 30
#define M 128

int main()
{
	srand(time(NULL));
	int count = 0;
	char instr[N][M] = { NULL }; // массив для записи строки из первого файла
	char outstr[M] = { NULL }; // массив для записи строки во второй файл
	FILE *fpRead, *fpWrite; 
	fpRead = fopen("1.txt", "r");
	fpWrite = fopen("2.txt", "w");

	if (fpRead == NULL)
	{
		puts("ERROR! File 1.txt not found!");
		return 1;
	}
	if (fpWrite == NULL)
	{
		puts("ERROR! File 2.txt not found!");
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