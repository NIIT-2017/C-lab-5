#include <stdio.h>
#include <string.h>
#include <time.h>
#include "task3.h"

char* mixLine(char* instr, char* outstr)
{

	char str[SIZE];
	char str_out[SIZE];
	outstr[0] = '\0';

	if (instr[strlen(instr) - 1] == '\n')
	{
        instr[strlen(instr) - 1] = '\0';
	}

	for (int k = 0; k < strlen(instr); k++)
	{
		int count = 0;
		for (int i = k; instr[i] != ' ' && instr[i] != '\0'; i++)
		{
			if (instr[i] != ' ')
			{
				str[count] = instr[i];
				count++;
			}

			if (instr[i + 1] == ' ' || instr[i + 1] == '\0')
			{
				str[count] = '\0';
				mixChars(str, str_out);

				int len = strlen(outstr);

				for (int j = 0; j <= strlen(str_out); j++)
				{
					outstr[len + j] = str_out[j];
					if (outstr[len + j] == '\0')
					{
						outstr[len + j] = ' ';
						outstr[len + j + 1] = '\0';
					}
				}
			}
			k++;
		}
	}

	if (outstr[strlen(outstr) - 1] == ' ')
	{
        outstr[strlen(outstr) - 1] = '\0';
	}

	return outstr;
}

char* mixChars(char* in, char* out)
{
	srand(time(NULL));
	for (int i = 0; i <= strlen(in); i++)
	{
		out[i] = in[i];
	}
	for (int j = 1; j < (strlen(out) - 1); j++)
	{
		int pos = rand() % (strlen(out) - 1 - j) + j;
		char buf = out[j];
		out[j] = out[pos];
		out[pos] = buf;
	}
	return out;
}
