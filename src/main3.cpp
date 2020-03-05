#include <stdio.h>
#include <string.h>
#include "task3.h"
int main()
{
	char instr[256];
	char outstr[256];
	long int beginStr = 0;
	int eof = 0;
	FILE* fp;
	while (!eof)// if file is empty eof=0
	{
		fp = fopen("C:\\labsss\\str.txt", "r+");
		fseek(fp, beginStr, SEEK_SET);//start of file
		if (!(fgets(instr, 256, fp)))
			break;
		eof = feof(fp);
		fclose(fp);
		fp = fopen("C:\\labsss\\str.txt", "r+");
		fseek(fp, beginStr, SEEK_SET);
		fputs(mixLine(instr, outstr), fp);
		beginStr = ftell(fp);
		fclose(fp);
	}
	return 0;
}