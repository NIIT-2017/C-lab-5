#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // rand() & strcmp
#include <ctype.h> // isspace()
#include <time.h>
#include "task1.h"
#define IN 1
#define OUT 0

char *randomWords(char *in, char *out)
{
	char *p_in[S] = { NULL };

	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';

	int i = 0;
	int flag = OUT;
	int count = 0;


	while (in[i])
	{
		if (!isspace(in[i]) && flag == OUT)
		{
			flag = IN;
			p_in[count] = &(in[i]);
			count++;
		}
		else if (isspace(in[i]) && flag == IN)
			flag = OUT;
		i++;
	}



	do
	{
		char *tmp = NULL;
		int randomNumber = 0;
		int c = count; //current count
		while (c > 1)
		{
			randomNumber = rand() % c;
			if (randomNumber != c - 1)
			{
				tmp = p_in[c - 1];
				p_in[c - 1] = p_in[randomNumber];
				p_in[randomNumber] = tmp;
				c--;
			}	
		}

		int j = 0;
		for (i = 0; i < count; i++)
		{
			while (*p_in[i] != ' ' && *p_in[i] != '\0')
				out[j++] = *(p_in[i]++);
			if (i < count - 1)
				out[j++] = ' ';
		}
		out[j] = '\0';

	} while (strcmp(out, in) == 0 && count > 1);

	return out;
}