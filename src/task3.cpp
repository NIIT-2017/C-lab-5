#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 256

char *mixChars(char *in, char *out)
{
	srand(time(NULL));
	
	int i = 0, lenght = 0;
	
	while (in[i] != ' ' && in[i] != '\0' && in[i] != '\n')
	{
		out[i] = in[i];
		lenght++;
		i++;
	}

	if (lenght > 3)
	{
		for(i = 1; i < lenght - 2; i++)
		{
			int k = rand() % (lenght - 2) + 1;
			if (k != i)
			{
				char temp = out[i];
				out[i] = out[k];
				out[k] = temp;
			}
		}
	}

	return out;
}

char *mixLine(char *instr, char *outstr)
{
	int i = 0, state = 0;

	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';

	while (instr[i])
	{
		if (instr[i] != ' ' && state == 0)
		{
			state = 1;
			mixChars(&instr[i], &outstr[i]);
		}
		else if (instr[i] == ' ' && state == 1)
		{
			outstr[i] = instr[i];
			state = 0;
		}
		i++;
	}

	outstr[i] = '\0';
	
	return outstr;
}