#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"
#define N 256



int main()
{
	char in[N] = { 0 };
	char out[N] = { 0 };
	FILE *f_In;		// open the file
	f_In = fopen("text.txt", "r");
	if (f_In == NULL)		// check opening
	{
		puts("FATAL ERROR! COULDN'T READ INPUT FILE! ALARM!");
		return 1;
	}

	while (fgets(in, N, f_In) != NULL)
	{
		if (in[strlen(in) - 1] == '\n')		// kill '\n'
			in[strlen(in) - 1] = '\0';

		randomWords(in, out);
		puts(out);

		for (int i = 0; i < N; i++)		// clear "in" and "out"
		{
			in[i] = '\0';
			out[i] = '\0';
		}
	}


	fclose(f_In);
	return 0;
}