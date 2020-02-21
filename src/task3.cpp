#include <stdio.h>
#include <string.h>
#include "task3.h"

#define SIZE 256

char* mixLine(char* instr, char* outstr)
{
	outstr[0] = '\0';
	char word[SIZE];
	char wordOut[SIZE];

	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';

	for (int ch = 0; ch < strlen(instr); ch++)
	{
		int wordLength = 0;

		for (int i = ch; instr[i] != ' ' && instr[i] != '\0'; i++)
		{
			if (instr[i] != ' ')
			{
				word[wordLength] = instr[i];
				wordLength++;
			}

			if (instr[i + 1] == ' ' || instr[i + 1] == '\0')
			{
				word[wordLength] = '\0';
				mixChars(word, wordOut);

				int length = strlen(outstr);

				for (int j = 0; j <= strlen(wordOut); j++)
				{
					outstr[length + j] = wordOut[j];
					if (outstr[length + j] == '\0')
					{
						outstr[length + j] = ' ';
						outstr[length + j + 1] = '\0';
					}
				}
			}
			ch++;
		}
	}

	if (outstr[strlen(outstr) - 1] == ' ')
		outstr[strlen(outstr) - 1] = '\0';

	return outstr;
}


char* mixChars(char* in, char* out)
{
	for (int k = 0; k <= strlen(in); k++)
	{
		out[k] = in[k];
	}

	for (int j = 1; j < (strlen(out) - 1); j++)
	{
		int position = rand() % (strlen(out) - 1 - j) + j;
		char buf = out[j];
		out[j] = out[position];
		out[position] = buf;
	}

	return out;
}
