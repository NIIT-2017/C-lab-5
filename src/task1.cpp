#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 256
#define inWord 1
#define outWord 0



char * randomWords(char * in, char *out)
{
	char *p[N] = { 0 };
	char *buf;

	unsigned int i = 0, j = 0, count=0,q;
	char flag = outWord;

	//put each word adress into pointer *p[]
	while (in[i])
	{
		if (in[i] != ' ' && flag == outWord)
		{
			p[j] = &in[i];
			i++;
			j++;
			flag = inWord;
			count++;
		}
		else if (in[i] == ' ' && flag == inWord)
		{
			i++;
			flag = outWord;
		}
		else 
			i++;
	}

	// mixing words
	srand(time(NULL));
	for (i = 0; i < count; i++)
	{
		q = rand()%(count);
		buf = p[i];
		p[i] = p[q];
		p[q] = buf;
	}

	// put mixed string into OUT
	j = 0;
	for (i = 0; i < count; i++)
	{
		while (*p[i] && *p[i] != ' ')
		{
			out[j] = *p[i];
			j++;
			*p[i]++;
		}
		out[j] = ' ';
		j++;

	}
	out[j - 1] = '\0';
	return out;
}