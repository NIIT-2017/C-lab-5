#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"
#include <string.h>
#define IN 1
#define OUT 0

char *mixLine(char *instr, char * outstr)
{
	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';

	int flag = OUT;
	char *firstLetter;		
	char *lastLetter;	

	for (int i = 0; i < strlen(instr); i++)
		outstr[i] = instr[i];	

	for (int i = 0; instr[i]; i++)
	{
		if (instr[i] != ' ' && flag == OUT)
		{
			flag = IN;
			firstLetter = &outstr[i];
		}
		else if (instr[i] != ' ' && flag == IN && instr[i + 1] == '\0')
		{
			lastLetter = &outstr[i];
			mixChars(firstLetter, lastLetter);	 
		}
		else if (instr[i] == ' ')
		{
			if (flag == IN)
			{
				lastLetter = &outstr[i - 1];
				mixChars(firstLetter, lastLetter);	
			}
			flag = OUT;
		}
	}
	return outstr;
}

char *mixChars(char *in, char *out)
{
	srand(time(0));
	int random;
	char buf;
	in++;
	while (in < (out - 1))	
	{
		random = rand() % (out - in);
		buf = *in;
		*in = *(in + random);
		*(in + random) = buf;

		in++;		
	}
	return out;		
}