//Clab5 task3

#include "task3.h"

int main()
{
	char instr[SIZE];
	char outstr[SIZE];

	FILE* fp_in = fopen("FILE.txt", "r");
	FILE* fp_out = fopen("FILE_out.txt", "w");

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