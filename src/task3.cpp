#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task3.h"


char* mixChars(char* in, char* out)
{
	srand(time(NULL));

	int i = 0, word = 0;

	while (in[i] != ' ' && in[i] != '\0 ' && in[i] != '\n')
	{
		out[i] = in[i];
		word++;
		i++;
	}

	if (word > 3) /* слово больше 3х символов*/
	{
		i = 1;
		while( i < (word-1))
		{
			int k = rand() % (word-i-1) + 1;
			if (k != i)
			{
				char tmp = out[word - i];
				out[word - i] = out[k];
				out[k] = tmp;
			}
			i++;
		}
	}

	return in + word;
}

char* mixLine(char* instr, char* outstr)
{
	
    int i = 0, inWord = 0;
    outstr[i] = '\0';
	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';

	while (instr[i])
	{
		if (instr[i] != ' ' && inWord == 0)
		{/* начало слова*/
			inWord = 1;
			mixChars(&instr[i], &outstr[i]);
		}
		else if (instr[i] == ' ' && inWord == 1)
		{/* конец слова*/
			outstr[i] = instr[i];
			inWord = 0;
		}
		i++;
	}

	
	return outstr;
}