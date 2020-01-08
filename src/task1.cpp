#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char* randomWords(char* in, char* out)
{
	int inWord = 0, //флаг нахождения в слове
		count = 0, //счетчик количества слов
		i = 0;
	char* buf[64];

	for (; i < 256 && in[i]; i++) // считаем количество слов и создаем массив указателей на первые буквы слов
	{
		if (in[i] == ' ')//между слов
			inWord = 0;
		else if (in[i] != ' ' && inWord == 0)//только что вошли в слово
		{
			inWord = 1;
			buf[count++] = &in[i];
		}
	}
	buf[count] = &in[i]; //записываем указатель на \0
	
	if (*in != 0) // заполняем массив out
	{
		int l = 0,
			p = 0,
			max = count;
		char* bubble = NULL;
		srand(time(NULL));
		for (; max > 0; max--)
		{
			p = rand() % max;
			for (int k = 0; *(buf[p] + k) != '\0' && *(buf[p] + k) != ' '; k++, l++)
				out[l] = *(buf[p] + k);
			out[l] = ' ';
			l++;
			while (*buf[p] != '\0')
			{
				buf[p] = buf[p + 1];
				p++;
			}
		}
		if (out[l - 1] == ' ')
			out[l - 1] = '\0';
		else
			out[l] = '\0';
	}
	else
		out[0] = 0;

	return out;
}