#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task1.h"

void swap(char*pin[], int cp);
void fillOut(char* pin[], int cp, char out[]);
int getArrPointers(char*pin[], char in[]);

char* randomWords(char* in, char* out)
{
	char* pin[SIZE];
	int cp = getArrPointers(pin, in);

	time_t now;
	time(&now);
	srand((unsigned int)now);
	rand();

	swap(pin, cp);
	fillOut(pin, cp, out);

	return out;
}

int getArrPointers(char* pin[], char in[])
{
	int i = 0, inWord = 0;
	int cp = 0;
	while (in[i])
	{
		if (in[i] != ' ' && inWord == 0)
		{
			pin[cp] = in + i;
			cp++;
			inWord = 1;
		}
		else if (in[i] == ' ' && inWord == 1)
			inWord = 0;
		i++;
	}
	return cp;
}

void swap(char* pin[], int cp)
{
	int i, j;
	char* temp;
	if (cp == 2)
	{
		temp = pin[0];
		pin[0] = pin[1];
		pin[1] = temp;
	}
	else
		for (i = 0; i < cp - 1; i++)
		{
			j = rand() % cp;
			temp = pin[i];
			pin[i] = pin[j];
			pin[j] = temp;
		}
}

void fillOut(char* pin[], int cp, char out[])
{
	int no = 0;
	int i, j;
	for (i = 0; i < cp; i++)
	{
		j = 0;
		while (*(pin[i] + j) != ' ' && *(pin[i] + j) != '\0')
		{
			out[no] = *(pin[i] + j);
			no++;
			j++;
		}
		if (i < cp - 1)
		{
			out[no] = ' ';
			no++;
		}
		else
			out[no] = '\0';
	}

}