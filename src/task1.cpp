#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h> 
#include <time.h>
#include "task1.h"

char *randomWords(char *in, char *out)
{
	char *inWord[256] = { 0 };
	int state;
	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';

	int i = 0;
	int flag = 0;
	int count = 0;

	while (in[i])
	{
		if (!isspace(in[i]) && flag == 0)
		{
			flag = 1;
			inWord[count] = &(in[i]);
			count++;
		}
		else if (isspace(in[i]) && flag == 1)
			flag = 0;
		i++;
	}

	do
	{
		char *tmp = 0;
		int randomNumber = 0;
		int c = count;
		while (c > 1)
		{
			randomNumber = rand() % c;
			if (randomNumber != c - 1)
			{
				tmp = inWord[c - 1];
				inWord[c - 1] = inWord[randomNumber];
				inWord[randomNumber] = tmp;
				c--;
			}
		}
		int j = 0;
		for (i = 0; i < count; i++)
		{
			while (*inWord[i] != ' ' && *inWord[i] != '\0')
				out[j++] = *(inWord[i]++);
			if (i < count - 1)
				out[j++] = ' ';
		}
		out[j] = '\0';

	} 
	while (strcmp(out, in) == 0 && count > 1);
	return out;
}