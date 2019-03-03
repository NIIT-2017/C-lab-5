#define N 256
#include <stdlib.h>
#include <stdio.h>

char * randomWords(char * in, char *out)
{
	char *p[N] = { 0 };

	int i = 0, j = 0;
	int inWord = 0;
	int count = 0;

	while (in[i])
	{
		if (in[i] != ' ' && inWord == 0)
		{
			inWord = 1;
			p[count] = &in[i];
			count++;
		}
		else if (in[i] == ' ' && inWord == 1)
			inWord = 0;
		i++;
	}


	for (int r = 0; count - 1 >= 0; count--)
	{

		r = rand() % count;

		while (*p[r] != ' ' && *p[r] != '\0')
		{
			out[j] = *p[r];
			*p[r]++;
			j++;
		}
		if (count - 1 > 0)
			out[j++] = ' ';

		p[r] = p[count - 1];
		p[count - 1] = '\0';

	}
	out[j] = '\0';

	return out;
}