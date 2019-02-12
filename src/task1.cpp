
#include "task1.h"
#include <string.h>


char * randomWords(char * in, char *out)
{
	char * pointers[256] = { 0 };
	int count = 0;  //считает реальное количество слов
	int inWord = 0; //флаг обработки слова
	for (int i = 0; in[i] != '\0';i++)
	{
		if ((in[i] >= 'A' && in[i] <= 'Z')
			|| (in[i] >= 'a' && in[i] <= 'z')
			|| (in[i] >= '!' && in[i] <= '9'))
		{
			if (!inWord) //inWord==0; or inWord!=0;
			{
				inWord = 1;
				pointers[count++] = in + i; // указатель , так как к имени массива мы прибавляем число 
			}
		}
		else
		{inWord = 0;}
	}
	int count2 = 0;

	for (int i = count - 1; i >= 0; i=i-2)
	{
		int j = 0;
		int a = strlen(in) - 1;
		while ((pointers[i][j] >= 'A' && pointers[i][j] <= 'Z')
			|| (pointers[i][j] >= 'a' && pointers[i][j] <= 'z')
			|| (pointers[i][j] >= '!' && pointers[i][j] <= '9'))   // или (*(pointers[i]+j))
		{
			*(out + count2) = pointers[i][j];
			count2++;
			j++;
		}
		if (i >= 0)
		{
			*(out + count2) = ' ';
		}
		count2++;
	}
	
	for (int i = count - 2; i >= 0; i=i-2)
	{
		int j = 0;
		int a = strlen(in) - 1;
		while ((pointers[i][j] >= 'A' && pointers[i][j] <= 'Z')
			|| (pointers[i][j] >= 'a' && pointers[i][j] <= 'z')
			|| (pointers[i][j] >= '!' && pointers[i][j] <= '9'))   // или (*(pointers[i]+j))
		{
			*(out + count2) = pointers[i][j];
			count2++;
			j++;
		}
		if (i > 0)
		{
			*(out + count2) = ' ';
		}
		count2++;
	}
	*(out + count2 - 1) = '\0';
	return out;

}