#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "task3.h"

int writeWordToOutStr(char *outword, char*outstr, int cs)
{
	int j = 0;
	while (outword[j])
	{
		outstr[cs] = outword[j];
		cs++;
		j++;
	}
	outstr[cs] = ' ';
	cs++;
	return cs;
}

void getWordFromInStr(char* p, char* in)
{
	int j = 0, cw = 0;
	while (*(p + j) != ' ' && *(p + j) != '\0')
	{
		in[cw] = *(p + j);
		cw++;
		j++;
	}
	in[cw] = '\0';

}

int getArrPointer(char* pin[], char in[])
{
	int i = 0, inWord = 0;
	int cp = 0;
	while (in[i])
	{
		if (in[i] != ' ' && inWord == 0)
		{
			pin[cp] = in + i;
			cp++;
			inWord = 1;
		}
		else if (in[i] == ' ' && inWord == 1)
			inWord = 0;
		i++;
	}
	return cp;
}

char* mixChars(char* in, char* out)
{
	int i = 0;
	char temp;
	while (in[i])
	{
		out[i] = in[i];
		i++;
	}
	out[i] = '\0';

	if (strlen(out) == 4)
	{
		temp = out[1];
		out[1] = out[2];
		out[2] = temp;
	}
	else if (strlen(out) > 4)
	{
		int swap = 0;
		for (i = 1; i < strlen(out) - 1; i++)
		{
			swap = rand() % (strlen(out) - 2);
			temp = out[i];
			out[i] = out[1 + swap];
			out[1 + swap] = temp;
		}
	}
	return out;
}

char* mixLine(char* instr, char* outstr)
{

	char in[MAX_ROW_SIZE];
	char out[MAX_ROW_SIZE];
	int cw = 0;

	char* pin[MAX_ROW_SIZE];
	int cp = 0; 
	cp = getArrPointer(pin, instr);

	int i,j, cs=0;

	time_t now;
	time(&now);
	srand((unsigned int)now);
	rand();

	for (i = 0; i < cp; i++)
	{

		getWordFromInStr(pin[i], in);

		mixChars(in, out);
		
		cs = writeWordToOutStr(out, outstr, cs);

		if (i == cp - 1)
			outstr[cs-1] = '\0';

	}

	return outstr;
}
