#include <string.h>
#include <ctime>
#include <iostream>

char  *mixChars(char *in, char *out)
{
	int i;
	int lengthIn;
	int randValue;
	int posInOut;
	lengthIn = strlen(in);
	out[0] = in[0];
	out[lengthIn-1] = in[lengthIn-1];
	srand(time(0));
	if (lengthIn>2)
		randValue = rand() % (lengthIn-2);
	for (i = 1; i < lengthIn-1; i++)
	{
		posInOut = i + randValue;
		if (posInOut > lengthIn - 2)
			posInOut -= lengthIn-2;
		out[posInOut] = in[i];
	}
	out[lengthIn] = '\0';
	return out;
}

char *mixLine(char *instr, char * outstr)
{
	char wordIn[100];
	char wordOut[100];
	int i;
	int posInWord;
	i = 0;
	while (instr[i])
	{
		if (instr[i] == ' '||instr[i]=='\n')
		{
			outstr[i] = instr[i];
			i++;
			continue;
		}
		posInWord = 0;
		while (instr[i] && instr[i] != ' '&&instr[i] != '\n')
			wordIn[posInWord++] = instr[i++];
		wordIn[posInWord] = '\0';
		mixChars(wordIn, wordOut);
		while (posInWord)
		{
			outstr[i - posInWord] = wordOut[strlen(wordOut)-posInWord];
			posInWord--;
		}
	}
	outstr[i] = '\0';
	return outstr;
}