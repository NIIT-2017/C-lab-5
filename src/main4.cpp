#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "task1.h"
#define N 100

int main()
{
	char in[N], out[N];
	FILE * fp;
	if ((fp = fopen("text.txt", "r")) == NULL)
	{
		printf("Error read file!\n");
		return 1;
	}

	while (fgets(in, N, fp) != NULL)
	{
		randomWords(in, out);
		puts(out);

	}
	fclose(fp);
	return 0;
}
	
