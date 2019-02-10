#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task3.h"
#define N 256

int main()
{
	char in[N] = { 0 };
	char out[N]= {0};
	int count = 0;

	FILE *f_In;		// open the input file
	f_In = fopen("text.txt", "r");
	if (f_In == NULL)
	{
		puts("ERROR! INPUT FILE NOT FOUND!");
		return 1;
	}

	FILE *f_Out;		// open the output file
	f_Out = fopen("output.txt", "w");
	if (f_Out == NULL)
	{
		puts("ERROR! OUTPUT FILE NOT FOUND!");
		return 1;
	}

	while (count < N && fgets(in, N, f_In) != NULL)		// read the file 
	{
		mixLine(in, out);		
		fputs(out, f_Out);		// print output string to output file
		fputs("\n", f_Out);
		for (int i = 0; i < N; i++)		// clear in and out
		{
			in[i] = '\0';
			out[i] = '\0';
		}
		count++;
	}

	puts("Done!");
		
	fclose(f_In);
	fclose(f_Out);
	return 0;
}