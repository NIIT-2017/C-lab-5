#include "task1.h"
#define POINTERS_NUM 50
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

char * randomWords(char * in, char *out)
{
	char *pointers[POINTERS_NUM] = { NULL };
	int count = 0, inWord = 0;
	for (int i = 0; in[i]; i++)					//заполнение массива указателей
	{
		if (in[i] != ' ' || !in[i+1])
		{
			if (!inWord)
			{
				inWord = 1;
				pointers[count++] = in + i;
			}
		}
		else inWord = 0;
	}
	char *temp = NULL;								//перемешивание указателей
	for (int i = 0; i < count-1; i++)
	{
		int randInd = rand() % (count);
		temp = pointers[i];
		pointers[i] = pointers[randInd];
		pointers[randInd] = temp;
	}
	int outInd = 0;								//заполнение строки out
	for (int i = 0; i < count; i++)
	{
		int j = 0;
		while (pointers[i][j] != ' ' && pointers[i][j] && pointers[i][j] !='\n')
		{
			out[outInd++] = pointers[i][j];
			j++;
		}
		out[outInd++] = ' ';
	}
	out[outInd - 1] = '\0';
	return out;
}