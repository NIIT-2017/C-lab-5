#include <stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define N 256

char *mixChars(char *in, char *out) /*перемешивание символов в одном слове*/
{
	sscanf(in, "%s", out);
	int size = strlen(out);
	if (size<=3)
		return out;
	if (size == 4)
	{
		char t = out[1];
		out[1] = out[2];
		out[2] = t;
		return out;
	}
	if (size > 4 && strcmp(in, out) == 0)
	{
		for (int j = 1; j < (size - 1); j++)
		{
			int k = rand() % (size - 2) + 1;
			char t = out[j];
			out[j] = out[k];
			out[k] = t;
		}
	}
	return out;
}
char *mixLine(char *instr, char * outstr) /*перемешивание для целой строки*/
{
	int i = 0, j = 0, k = 0;
	char in[N] = { 0 }, out[N] = { 0 };

	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';

	for (i = 0; instr[i] != '\0'; i++)
	{
		int count = 0;
		for (i; (instr[i] != ' ') && (instr[i] != '\0'); i++)
		{
			in[count] = instr[i];
			count++;
		}
		in[count] = '\0';
		mixChars(in, out);

		for (k=i-count, j = 0; j<count; j++, k++)
		{
			outstr[k] = out[j];
		}
		outstr[k] = ' ';
	}
	outstr[--i] = '\0';
return outstr;
}