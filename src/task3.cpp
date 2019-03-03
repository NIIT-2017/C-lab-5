#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"
#define N 256
#define inWord 1
#define outWord 0

char *mixLine(char *instr, char * outstr)
{
	if (instr[strlen(instr) - 1] == '\n')	
		instr[strlen(instr) - 1] = '\0';
	
	int flag = outWord;
	char *firstLetter;		// pointer to the first letter in each WORD
	char *lastLetter;		// ... last ...

	for (int i=0;i<strlen(instr);i++)
		outstr[i] = instr[i];	// programm will read instr and mix letter in outstr. Instr will not damaged
	
	for (int i = 0; instr[i]; i++)
	{
		if (instr[i] != ' ' && flag == outWord)
		{
			flag = inWord;
			firstLetter = &outstr[i];
		}
		else if (instr[i] != ' ' && flag == inWord && instr[i + 1] == '\0')
		{
			lastLetter = &outstr[i];
			mixChars(firstLetter, lastLetter);	// mix letters in the LAST word 
		}
		else if (instr[i] == ' ')
		{
			if (flag == inWord)
			{
				lastLetter = &outstr[i-1];
				mixChars(firstLetter, lastLetter);	// mix letters in word
			}
			flag = outWord;
		}
	}
	return outstr;
}

char *mixChars(char *in, char *out)
{
/*	int count = 0;
	while (in+count < out)		
		count++;
	count--;			// we have "count" letters between the first and the last letters
	
	if (count <= 1)		// not enough letters in word!
		return out;
*/
	srand(time(NULL));
	int random;
	char buf;
	in++;
	while (in<(out-1))		// mix letters:
	{
		random = rand() % (out-in);	
		buf = *in;
		*in = *(in + random);
		*(in + random) = buf;
		
		in++;		// set adress to the next letter
	}
	return out;		// we don't gave to return something. Type 'void' could be better in this solution
}