#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORDS 30
#define ITERATION 21

char * randomWords(char * in, char *out)
{
	int i = 0, j = 0, k = 0, count = 0;
	char *word_ptr[WORDS] = { NULL };
	char *temp;

	if (in[strlen(in) - 1] == '\n') // убираем \n в конце строки
		in[strlen(in) - 1] = '\0';

	while (in[i] != '\0') // передаем адреса первых символов каждого слова в массив указателей
	{
		if (in[i] != ' ' && in[i] != '\0')
		{ 
			*(word_ptr + count) = &in[i];
			count++;
			while (in[i] != ' ' && in[i] != '\0')
				i++;
			i--;
		}
		i++;
	}

	for (i = 0; i < ITERATION; i++) // перемешиваем массив указателей случайным образом
	{
		j = rand() % count;
		k = rand() % count;
		while (j == k) // исключаем ложное тасование
			k= rand() % (count);
		temp = word_ptr[j];
		word_ptr[j] = word_ptr[k];
		word_ptr[k] = temp;
	}

	for (i = 0, j =0; i < count ; i++) // заполняем out для дальнейшего вывода
	{
		char *p = word_ptr[i];
		while (*p && *p != ' ')
			out[j++] = *p++;
		out[j++] = ' ';
	}
	out[--j] = '\0';
	return out;
}