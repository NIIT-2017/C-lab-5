#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"
#define IN 1
#define OUT 0

char *mixChars(char *in, char *out)  // shuffle characters in a single word
{
	int random = 0;
	int numberOfChars = 0;
	int number = 0;
	int j = 0;

	while (in[j] != ' ' && in[j] != '\0' && in[j] != '\n')
	{
		out[j] = in[j];
		numberOfChars++;
		j++;
	}
	

	number = numberOfChars - 1;
	char tmp = '\0';

	while (number > 2)
	{
		random = rand() % number;
		if ((random != (number - 1)) && random) /* if (random != 0) */
		{
			tmp = out[number - 1];
			out[number - 1] = out[random];
			out[random] = tmp;
			number--;
		}
	}

	return out;
}


char *mixLine(char *instr, char *outstr)  // shuffle for the whole string
{
	int i = 0;
	int flag = OUT;
	
	while (instr[i])
	{
		if (instr[i] != ' ' && flag == OUT)
		{
			flag = IN;
			mixChars(&instr[i], &outstr[i]);
			i++;
		}
		else if (instr[i] != ' ' && flag == IN)
			i++;
		else if (instr[i] == ' ' && flag == IN)
		{
			flag = OUT;
			outstr[i] = instr[i];
			i++;
		}
		else if (instr[i] == ' ' && flag == OUT)
		{
			outstr[i] = instr[i];
			i++;
		}
	}
	outstr[i] = '\0';


	return outstr;
}