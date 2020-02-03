//Clab5 task3

#include "task3.h"

char* mixLine(char* instr, char* outstr)
{
	outstr[0] = '\0';
	char wordIn[SIZE];
	char wordOut[SIZE];
	
	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';

	for (int ch = 0; ch < strlen(instr); ch++)
	{
		int letterCounter = 0;

		for (int i = ch; instr[i] != ' ' && instr[i] != '\0'; i++)
		{
			if (instr[i] != ' ')
			{
				wordIn[letterCounter] = instr[i];
				letterCounter++;
			}

			if (instr[i+1] == ' ' || instr[i + 1] == '\0')
			{
				wordIn[letterCounter] = '\0';
				mixChars(wordIn, wordOut);

				int length = strlen(outstr);

				for (int outCh = 0; outCh <= strlen(wordOut); outCh++)
				{
					outstr[length+outCh] = wordOut[outCh];
					if (outstr[length + outCh] == '\0')
					{
						outstr[length + outCh] = ' ';
						outstr[length + outCh + 1] = '\0';
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
	time_t now;
	time(&now);
	srand(now);

	for (int k = 0; k <= strlen(in); k++)
	{
		out[k] = in[k];
	}

	for (int j = 1; j < (strlen(out)-1); j++)
	{
		int position = rand() % (strlen(out)-1-j) + j;
		char buf = out[j];
		out[j] = out[position];
		out[position] = buf;
	}

	return out;
}

