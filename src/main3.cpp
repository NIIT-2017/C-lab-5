#define _CRT_SECURE_NO_WARNINGS
#include "task3.h"
#include <stdio.h>

#define SIZE 256

int main()
{
	char instr[SIZE];
	char outstr[SIZE];
	FILE* fp_in = fopen("text.txt", "r"); //פאיכ ס ןנמגונמקםûל עוסעמל
	FILE* fp_out = fopen("text_out.txt", "w"); //פאיכ ס 
	for (; ; )
	{
		if (fgets(instr, SIZE, fp_in) == NULL)
			break;
		mixLine(instr, outstr);
		fputs(outstr, fp_out);
		fputs("\n", fp_out);
	}
	fclose(fp_in);
	fclose(fp_out);
	return 0;
}