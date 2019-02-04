#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * randomWords(char * in, char *out)
{
	char *word[10] = {NULL};
	char *pt ;
	int q, t = 0, i, j = 0, k = 0, inWord = 0, len = 0, rnd = 0;
	len = strlen(in);
	for (i = 0; i < len; i++)
	{
		if (in[i] != ' '  && inWord == 0)
		{
			*(word + k) = &in[i];
			k++;
			inWord = 1;
		}
		else if (in[i] == ' ' && inWord == 1)
			inWord = 0;
	}


	for (int i = 0, j=k-1; i < k; i++, j--)
	{
		rnd = rand() % k;
		pt = word[j];
		word[j] = word[rnd];
		word[rnd] = pt;
	}
	
	
	for (q = 0; q<k; q++)
	{
		len = strlen(*(word+q));
		for (j, t = 0; t < len; j++, t++)
		{

			if (*(*(word + q) + t) != ' ' && *(*(word + q) + t) != '\0'&& *(*(word + q) + t) != '\n')
				out[j] = *(*(word + q) + t);
			else
				break;
			
			
		}
		out[j] = ' ';
		j++;
	}
	out[j-1] = '\0';
	return out;
}