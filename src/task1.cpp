#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define COUNT_WORDS_MAX 20
#define LENGTH_WORDS_MAX 30

char * randomWords(char * in, char *out)
{
	char *pArr[COUNT_WORDS_MAX] = { 0 };
	int length = strlen(in);
	int countWords = 0;
		
	for (int i = 0; i < length; i++)
		(*(in + i) != ' ' && *(in + i) != '\0' && (i == 0 || *(in + i - 1) == ' ')) ? *(pArr + countWords++) = in + i : 0;
	
	if (countWords  ==0)
	{
		for(int i=0; i< length;i++)
			*(out + i) = *(in + i);
		*(out + length) = '\0';
		return out;
	}

	char *pTemp = 0;
	int randNum = 0;
	
	for (int j = 0; j < countWords - 1; j++)
	{
		pTemp = *(pArr + j);
		randNum = j + 1 + rand() % (countWords - (j + 1));
		*(pArr + j) = *(pArr + randNum);
		*(pArr + randNum) = pTemp;
	}
	
	pTemp = out;
	for (int j = 0; j < countWords; j++)
	{
		for (int i = 0; *(*(pArr + j) + i) != ' ' && *(*(pArr + j) + i) != '\0'; i++)
			*pTemp++ = *(*(pArr + j) + i);
		*pTemp++ = ' ';
	}
	*--pTemp = '\0';
	return out;

}
