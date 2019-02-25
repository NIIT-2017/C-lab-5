/*
ѕо€снение:
ƒл€ входной строки создаетс€ массив указателей на char, в который занос€тс€ адреса первых символов каждого слова.
«атем организуетс€ нова€ строка, при использовании этого массива из указателей.
ћассив из указателей должен объ€вл€тьс€ внутри функции randomWords.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char * randomWords(char * in, char *out)
{
	char *words[255] = { NULL };//массив указателей на первые буквы слов
	int i = 0, numWords = 1;
	srand(time(0));
	words[0] = &in[0];
	int flag = strlen(in);
	if (in[flag - 1] == '\n')
	{
		in[flag - 1] = '\0';
		flag = 1;
	}

	while (in[i] != '\0')//заполнение массива words указател€ми на первые буквы слов
	{
		if (in[i] == ' ' || in[i] == '\n')
		{
			i++;
			words[numWords] = &in[i];
			numWords++;
		}

		i++;
	}
	//-----Shake------
	int random = 0;
	char *temp;
	for (int i = 0; i < numWords; i++)
	{
		random = rand() % (numWords - 1);
		temp = words[random];
		words[random] = words[i];
		words[i] = temp;

	}
	//----Export in out----
	i = 0;
	int j = 0, count = 0;
	while (i < numWords)
	{

		while (*words[i] != ' '&& *words[i] != '\0')
		{
			out[j] = *words[i]++;
			j++;
		}

		out[j] = ' ';
		j++;
		i++;
	}
	if (flag == 1)
	{
		out[j - 1] = '\n';
	}
	return out;
}