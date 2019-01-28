#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"

int count = 0;

char *mixLine(char *instr, char * outstr)
{
	char in[256];
	char out[256];
	extern int count;
	int i = 0;
	char *p1 = instr;
	char *p2 = outstr;


	int len = strlen(instr);
	if (instr[len - 1] == '\n')
		instr[len - 1] = '\0';
	outstr[strlen(instr)] = ' ';
	outstr[strlen(instr)+1] = '\0';

	while (*p1 != '\0')
		*p2 = *p1, p1++, p2++;

	p1 = outstr; p2 = outstr;
	for (int state = 0; *p1 != '\0'; *p1++)
	{
		if (*p1 != ' ' && state == 0)
		{
			state = 1;
		}
		else if (*p1 == ' ' && state == 1)
		{
			state = 0;
			count = p1 - p2;
			if (count > 3)
			{
				i = 0;
				while (i < count)
				{
					in[i] = *(p1 - count + i);
					i++;
				}
				mixChars(in, out);
				i = 0;
				while (i < count)
				{
					*(p1 - count + i) = out[i];
					i++;
				}
			}
			p2 = p2 + count + 1;
		}
	}
	outstr[strlen(instr)] = '\0';
	return outstr;
}

char *mixChars(char *in, char *out)
{
	extern int count;
	int i = 0;
	char arr[10];
	
	while (i < (count - 2))
		arr[i] = '0', i++;

	i = 0;
	out[i] = in[i];
	out[count - 1] = in[count -1];
	
	int random;
	srand(time(NULL));
	for (int i = 0, l = 0; i < (count - 2);)
	{
		if (arr[random = rand() % (count - 2)] != '1')
		{
			arr[random] = '1';
			out[l + 1] = in[random + 1];
			i++, l++;
		}
	}
	return out;
}
