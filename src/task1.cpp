#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 256

char* randomWords(char* in, char* out)
{
	srand(time(NULL));

	char* words[SIZE] = { 0 };
	int i = 0, inWord = 0, wordCount = 0;
	while (in[i])
	{
		if ((in[i] != ' ') && (inWord == 0))
		{
			words[wordCount] = &in[i];
			inWord = 1;
			wordCount++;
		}
		else if ((in[i] == ' ') && (inWord == 1))
		{
			inWord = 0;
		}
		i++;
	}

	int j = 0;
	int size = wordCount;
	for (int i = 0; i < wordCount; i++)
	{
		int k = 0;
		int randIndex = rand() % size;
		while (*(words[randIndex] + k) != ' ' && *(words[randIndex] + k) != 0)
		{
			out[j] = *(words[randIndex] + k);
			k++;
			j++;
		}
		if (i != wordCount)
		{
			out[j] = ' ';
			j++;
		}
		else
		{
			out[j] = '\0';
		}
		words[randIndex] = words[size - 1];
		size--;
	}

	return out;
}