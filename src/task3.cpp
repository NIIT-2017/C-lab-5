#include <string.h>
#include <stdlib.h>
#include <time.h>
char* mixChars(char* in, char* out)
{
	char buf = 0;
	int lengthWord = 0;
	int randNum = 0;
	for (int i = 0; i < strlen(in); i++)//lenghtWord
	{
		if (in[i] != ' ' && in[i] != '\n')
		{
			out[i] = in[i];
			lengthWord = i;
		}
		else
			break;
	}
	srand(time(NULL));
	for (int i = 1; i < lengthWord - 1; i++)//
	{
		randNum = rand() % (lengthWord - i - 1) + 1;
		buf = out[lengthWord - i];
		out[lengthWord - i] = out[randNum];
		out[randNum] = buf;
	}
	return in + lengthWord;
}
char* mixLine(char* instr, char* outstr)
{
	outstr[strlen(instr)] = 0;
	for (int i = 0; i <= strlen(instr) - 1; i++)
	{
		if (instr[i] != ' ' && instr[i] != '\n')
		{
			i = mixChars(instr + i, outstr + i) - instr;
		}
		else
		{
			outstr[i] = instr[i];
		}
	}
	return outstr;
}