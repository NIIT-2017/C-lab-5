//#include "pch.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 128

char * randomWords(char * in, char *out)
{
	char *token[N];
	int i = 0, j = 0, count = 0;
	int state = 0;

	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = 0;

	for (i = 0; in[i]; i++)
	{
		if (in[i] != ' ' && state == 0)
		{
			token[count] = &in[i];
			state = 1;
			count++;
		}
		else if (in[i] == ' ' && state == 1)
			state = 0;
	}

	srand(time(0));
	for (i = 0; i < count; i++)
	{
		int a = rand() % count;
		char *temp = token[i];
		token[i] = token[a];
		token[a] = temp;
	}

	for (i = count - 1; i >= 0; i--)
	{
		while (*token[i] != ' ' && *token[i] != '\0')
		{
			out[j++] = *token[i];
			token[i]++;
		}
		out[j++] = ' ';
	}

	out[strlen(in)] = '\0';
	return out;
}