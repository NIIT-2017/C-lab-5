#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 24


char * randomWords(char * in, char *out)
{
	srand(time(NULL));
	if (in[strlen(in) - 1] == '\n') in[strlen(in) - 1] = '\0';
	char * p_in[N] = { NULL };
	int countW = 0, i = 0, j = 0, flag = 0;
	while (in[i] != '\0')
	{
		if (flag == 0 && in[i] != ' ')
		{
			flag = 1;
			p_in[countW] = &in[i]; // Does that f have the same effect: p_in[i] = &in[i]??? Nope, cuz then we'll get A LOT of SPACES!
			//*(p_in+countW) = &in[i]; <<< the same effect. 
			countW++;
		}
		if (in[i] == ' ')
		{
			flag = 0;
		}
		i++;
	}
	
	while (countW != 0)
	{
		i = rand() % countW;
		char * p_buf = p_in[i];
		while (*p_buf != ' ' && *p_buf != '\0')
		{
			out[j] = *p_buf;
			*p_buf++;
			j++;
		}
		out[j++] = ' ';
		char *p_swap = p_in[i]; // creating a temp buf so as to swap, concerned word's going to an end and being excepted
		p_in[i] = p_in[countW-1];// swap-swap
		p_in[countW-1] = p_swap;
		countW--;

	}

	out[strlen(out)-1] = '\0';


	return out;
}
