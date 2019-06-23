//#include "pch.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define N 128

char *mixChars(char *in, char *out)
{
	int i = 0, count = 0;
	while (isalpha(in[i]))
	{
		out[i] = in[i];
		count++;
		i++;
	}

	if (count >= 4)
	{
		for (i = 1; i < (count - 2); i++)
		{
			int j = rand() % (count - 2) + 1;
			if (j != i)
			{
				char temp = out[i];
				out[i] = out[j];
				out[j] = temp;
			}
		}
	}
	return out;
}

char *mixLine(char *instr, char * outstr)
{

	int i = 0;
	int state = 0;

	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = 0;

	for (i = 0; instr[i]; i++)
	{
		if (instr[i] != ' ' && state == 0)
		{
			mixChars(&instr[i], &outstr[i]);
			state = 1;
		}
		else if (instr[i] == ' ' && state == 1)
		{
			outstr[i] = instr[i];
			state = 0;
		}
	}
	outstr[i] = '\0';
	return outstr;
}