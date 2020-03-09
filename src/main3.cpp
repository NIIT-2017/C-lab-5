#include "task3.h"
#include <stdio.h>

int main()
{
	char instr[SIZE];
	char outstr[SIZE];
	FILE* fp_in = fopen("file.txt", "r");
	FILE* fp_out = fopen("file_done.txt", "w");
	while(1)
	{
        if (fgets(instr, SIZE, fp_in) == NULL)
        {
            break;
        }
		mixLine(instr, outstr);
		fputs(outstr, fp_out);
		fputs("\n", fp_out);
	}

	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
