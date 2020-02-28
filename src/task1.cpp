#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "task1.h"
#define SIZE 256

char * randomWords(char* in, char* out)
{
	srand(time(NULL));
	char* arr[SIZE];
	int i = 0, j = 0 , k = 0, flag = 0;
	char* str;
	while (*in)
	{
		if (*in != ' ' && flag == 0)
		{
			arr[i] = in;
			i++;
			flag = 1;
			k++;
		}
		else if (*in == ' ' && flag == 1)
		{
			flag = 0;
		}
		in++;
	}

	for (i = k - 1; i >= 1;  i--)
	{
		j = rand() % (i + 1);
		str = arr[j];
		arr[j] = arr[i];
		arr[i] = str;
	}

	for (j = 0; j < k; j++)
	{
		str = arr[j];
		while (*str!= ' ' && *str != '\0')
		{
			*out = *str;
			str++;
			out++;
		}
		*out = ' ';
		out++;
	}
	out--;
	*out = 0;
	return out;
}
