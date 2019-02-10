#include <stdlib.h>
#include <string.h>
#define M 20

char *mixChars(char *in, char *out) // mix letters in one word
{
	int countLet = strlen(in);
	char change;
	int k = 0;

	for (int i = 0;i < countLet;i++)
		out[i] = in[i];

	out[countLet] = '\0';

	if (countLet < 4)
		return out;
		
	else if (countLet == 4)
	{
		change = out[1];
		out[1] = out[2];
		out[2] = change;
		return out;
	}

	else if (strcmp(in, out) == 0)
	{
		for (int j = 1; j < countLet - 1;j++)
		{
			k = rand() % (countLet - 2) + 1;
			change = out[j];
			out[j] = out[k];
			out[k] = change;
		}

	}

	return out;
}

char *mixLine(char *instr, char *outstr) // processing words in one line 
{
	char in[M] = { 0 };
	char out[M] = { 0 };

	int i = 0, j = 0, k = 0;
	int count = 0;

	while (instr[i])
	{
		for (count = 0; instr[i] != ' ' && instr[i] != '\0';i++)
		{
			in[count] = instr[i];
			count++;
		}
		in[count] = '\0';

		mixChars(in, out);

		for (k = i - count, j = 0;j < count;j++,k++)
			outstr[k] = out[j];
		
		outstr[k] = ' ';
		i++;
	}
	outstr[k++] = '\0';
	return outstr;
}