#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

char *mixChars(char *in, char *out) 
{
	char temp;
	sscanf(in, "%s", out);
	int len = strlen(out);
	if (len <= 3)//don't touch the word with the length even or less than 3 letters
		return out;
	if (4 == len) {
		temp = out[1];
		out[1] = out[2];
		out[2] = temp;
		return out;
	}
	if (len > 4)
	{
		do {
			for (int i = 1; i < (len - 1); i++)//mixing the letters in the word
			{
				int j = rand() % (len - 2) + 1;//begin from 1 since we don't change first symbol
				char temp = out[i];
				out[i] = out[j];
				out[j] = temp;
			}
		} while (strcmp(in, out) == 0);
	}
	return out;
}

char *mixLine(char *instr, char * outstr) //mixing for a string
{
	if (instr[strlen(instr) - 1] == '\n')//deleting \n in the end of the string
		instr[strlen(instr) - 1] = '\0';

	int inWord = 0;



	for (int i = 0; i <= strlen(instr); i++)
	{
		outstr[i] = instr[i];
	}

	for (int i = 0; outstr[i] != '\0'; i++)
	{
		char in[SIZE1] = { 0 };
		char out[SIZE1] = { 0 };
		if (outstr[i] == ' ')// cheking if we are in the word
			inWord = 0;//we are not in the word!
		else
		{
			if (!inWord)//if we were not in the word previously
			{
				inWord = 1;//now we are in the word

				for (int j = i, k = 0; ((outstr[j] != ' ') && (j < strlen(outstr))); j++, k++)// forming array in
				{
					in[k] = outstr[j];
				}

				mixChars(in, out);//mixing the order into the word

				int count1 = 0;
				for (int j = i, k = 0; out[k] != '\0'; j++, k++)
				{
					outstr[j] = out[k];
					count1++;
				}

				i = i + count1 - 1;
			}
		}
	}
	return outstr;
}