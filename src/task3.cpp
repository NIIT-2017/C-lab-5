#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mixChars(char *in, char *out)
{
	char ch = 0;
	int count = 0, rnd = 0, j;
	for (int i = 0; *(in + i) != ' ' && *(in + i) != '\0'; i++)
	{
		out[i] = in[i];
		count++;
	}
	
	for (j = 0; j<count; j++)
	{
		if (j != 0 && j != count - 1)
		{
			rnd = rand() % (count - 2) + 1;
			ch = out[j];
			out[j] = out[rnd];
			out[rnd] = ch;
		}
	}
	out[j] = '\0';
	return out;
}

char *mixLine(char *instr, char *outstr)
{
	if (instr[strlen(instr)-1] == '\n')
		instr[strlen(instr) - 1] = '\0';
		

	char *in[10] = { NULL };
	char out[50] = {0};
	int inWord = 0, len = 0, i, k = 0, q, j=0, t;
	len = strlen(instr);
	for (i = 0; i < len; i++)
	{
		if (instr[i] != ' '  && inWord == 0)
		{
			*(in + k) = &instr[i];
			k++;
			inWord = 1;
		}
		else if (instr[i] == ' ' && inWord == 1)
			inWord = 0;
	}

	for (q = 0; q < k; q++)
	{
		mixChars(*(in + q), out);
		len = strlen(out);
		for (j, t = 0; t < len; j++, t++)
		{
	
				outstr[j] = out[t];

		}
		outstr[j] = ' ';
		j++;
	}
	outstr[j - 1] = '\0';
	return outstr;
}

