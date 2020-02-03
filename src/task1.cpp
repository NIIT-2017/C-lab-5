//Clab5 task1

#include "task1.h"

char* randomWords(char* in, char* out)
{
	int j = 0, inWord = 0;
	char*p[SIZE];
	
	for (int i = 0; i < SIZE; i++)
	{
		if (in[i] != ' ' && inWord == 0)
		{
			p[j] = &in[i];
			inWord = 1;
			j++;
		}

		if (in[i] == ' ' && inWord == 1)
		{
			inWord = 0;
		}

		else if (in[i] == '\n')
			break;
	}

	j--;
	int len = j;
	int word = 0;
	
	time_t now;
	time(&now);
	srand(now);

	for (; j > 0; j--)
	{
		int position = rand() % (j);

		char* buf = p[j];
		p[j] = p[position];
		p[position] = buf;
	}

	for (; len >= 0; len--)
	{
		for (int k = 0; *(p[len] + k) != ' ' && *(p[len] + k) != '\n'; k++)
		{
			out[word] = *(p[len] + k);
			word++;
		}

		out[word] = ' ';
		word++;
	}

	out[word] = '\0';

	return out;
}


