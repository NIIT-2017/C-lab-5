#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "task3.h"

#define N 20
#define M 256


char* mixChars(char* in, char* out) {

	for (int i = 0; i < strlen(out); i++)
	{
		out[i] = '\0';
	}

	char* firstLetter = NULL;
	char* lastLetter = NULL;
	int w = 0;
	firstLetter = in;
	while (1) {
		in++;
		if (*in == ' ' || *in == '\0')
		{
			lastLetter = (in - 1);
			break;
		}
		w++;
	}
	out[0] = *firstLetter;
	out[w] = *lastLetter;

	for (int i = 0; i < w; i++)
	{
		out[i] = *firstLetter++;
	}

	for (int i = 1, j = 0; i < w - 1; i++)
	{
		j = 1 + rand() % (lastLetter - firstLetter - 1);
		char symbol = '\0';
		symbol = out[j];
		out[j] = out[i];
		out[i] = symbol;
	}

	return out;
}
char* mixLine(char* instr, char* outstr)
{
	for (int i = 0; i < M; i++)
		outstr[i] = '\0';

	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';
	char out[N] = { '\0' };

	int flag = 0;
	int wordCounter = 0;
	char* words[N] = { NULL };

	for (int i = 0, k = 0; instr[i] != '\0'; i++)
	{
		if (instr[i] != ' ' && flag == 0) {
			words[wordCounter] = &instr[i];
			flag = 1;
			mixChars(words[wordCounter], out);
			wordCounter++;
		}
		if (instr[i] == ' ' && flag == 1)
		{
			flag = 0;
			for (int j = 0; out[j] != '\0'; j++)
			{
				outstr[k] = out[j];
				k++;
			}
			outstr[k] = ' ';
			k++;
		}
		if (instr[i + 1] == '\0' && flag == 1)
		{
			for (int j = 0; out[j] != '\0'; j++)
			{
				outstr[k] = out[j];
				k++;
			}
		}
	}
	return outstr;
}