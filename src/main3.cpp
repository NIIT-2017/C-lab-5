#include <stdio.h>
#include <cstring>
#include "task3.h"
#define N 100
int main()
{
	char instr[N], outstr[N];

	FILE * fp;
	if ((fp = fopen("text.txt", "r")) == NULL)
	{
		printf("Error read file!\n");
		return 1;
	}

	while (fgets(instr, N, fp) != NULL)
	{
		mixLine(instr, outstr);
		puts(outstr);

	}
	fclose(fp);
	return 0;
}