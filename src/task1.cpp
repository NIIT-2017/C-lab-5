#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char * randomWords(char * in, char *out)
{
	int len = strlen(in);
	if (in[len - 1] == '\n')
		in[len - 1] = '\0';
	
	char *p[256];
	char arr[256] = { 0 };
	int count = 0;
	
	for (int i = 0, state = 0; in[i] != '\0'; i++)
	{
		if (in[i] != ' ' && state == 0)
		{
			state = 1;
			p[count] = &in[i];
			count++;
		}
		else if (in[i] == ' ' && state == 1)
			state = 0;
	}

	int random;
	srand(time(NULL));
	for (int i = 0, l = 0; i < count;)
	{
		if (arr[random = rand() % count] != '1')
		{
			arr[random] = '1';
			for (;*p[random] != ' '&& *p[random] != '\0'; l++, p[random]++)
				out[l] = *p[random];
			out[l] = ' ';
			l++;
			i++;
		}
	}

	out[strlen(in)] = '\0';
	return out;
}