#include <ctime>
#include <iostream>

bool isLetter(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;
	return false;
}

char * randomWords(char * in, char *out)
{
	char *words[20];
	int countWords;
	int countLetters;
	int rand_value;
	int randWord;
	
	int i;
	
	countWords = 0;
	while (*in)
	{
		if (isLetter(*in))
		{
			words[countWords] = in;
			while (isLetter(*in))
			{
				*in++;
			}
			countWords++;
		}
		*in++;
	}
	if (countLetters == 0)
		return in;
	srand(time(0));
	rand_value = 0 + rand() % countWords;
	while (rand_value == 0)
		rand_value = 0 + rand() % countWords;	
	countLetters = 0;
	for (i = rand_value; i < countWords+rand_value; i++)
	{
		randWord = i;
		if (randWord >= countWords)
			randWord -= countWords;
		while (isLetter(*words[randWord]))
		{
			out[countLetters] = *words[randWord];
			*words[randWord]++;
			countLetters++;
		}
		out[countLetters] = ' ';
		countLetters++;
	}
	out[countLetters-1] = '\0';
	return out;
}