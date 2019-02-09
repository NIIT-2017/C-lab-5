#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 256

char *randomWords(char *in, char *out)
{
	int i = 0, j = 0, count = 0, state = 0;
	char *ptr[N];
	int buf[] = { 0 };
	char *rptr;

	srand(time(NULL));

	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';

	while (in[i])
	{
		if (in[i] != ' ' && state == 0)
		{
			state = 1;
			ptr[count] = &in[i];
			count++;
		}
		else if (in[i] == ' ' && state == 1)
			state = 0;
		i++;
	}
	for (i = 0; i < count; i++)
	{
		int k = rand() % count;
		rptr = ptr[i];
		ptr[i] = ptr[k];
		ptr[k] = rptr;
	}
	for (i = 0; i < count; i++)
	{
		while (*ptr[i] != ' ' && *ptr[i] != '\0')
			out[j++] = *ptr[i]++;
		out[j++] = ' ';
	}
	out[strlen(in)] = '\0';
	return out;
}