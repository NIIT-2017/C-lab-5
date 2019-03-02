#include <cstring>
#include <stdlib.h>
#include "task3.h"
#define M 10

char *mixLine(char *instr, char *outstr)
{
	int size=0, i = 0, t=0;
	char in[M], out[M];
	while(size < strlen(instr))
	{
		int r = 0;
		while (instr[i] != ' ' & instr[i] != '\0')
		{
			in[r] = instr[i];
			i++;
			r++;
			size++;
		}
		i++;
		in[r] = '\0';
		size++;
		mixChars(in, out);
		int j = 0;
		while (out[j] != '\0')
		{
			outstr[t] = out[j];
			j++;
			t++;
		}
		outstr[t] = ' ';
		t++;
	}
	outstr[t-1] = '\0';
}



char *mixChars(char *in, char *out)
{
	int j = 0, k = 0, charInWord = strlen(in);
	if (charInWord > 3)
	{
		out[j] = in[j];
		j++;
		while (in[j + 1] != 0)
		{
			k = (rand() % (charInWord - 2) + 1);
			out[j] = in[k];
			j++;
		}
		out[j] = in[j];
		out[j+1] = '\0';
	}
	else
	{
		while (in[j] != '\0')
		{
			out[j] = in[j];
			j++;
		}
		out[j++] = '\0';
	}
	return 0;
}

