#define POINT_NUM 32																//предполагаемое максимальное количество слов в строке
#define BUF_WORD_SIZE 32															//предполагаемая максимальная длина слова
#define _CRT_SECURE_NO_WARNINGS
#include "task3.h"
#include <stdlib.h>

char *mixChars(char *in, char *out)
{
	int charCount = 0;
	while (in[charCount] != ' ' && (in[charCount] != '\n' && in[charCount] ))		//копирование строки in в out
	{
		out[charCount] = in[charCount];
		charCount++;
	}
	char temp;																		//перемешивание строки out
	for (int i = 1; i < charCount - 2; i++)
	{
		int RandInd = rand() % (charCount - 2) + 1;
		temp = out[i];
		out[i] = out[RandInd];
		out[RandInd] = temp;
	}
	return out;
}
char *mixLine(char *instr, char *outstr)
{
	char *pointers[POINT_NUM] = { 0 };
	int inWord = 0, wordCount = 0;
	for (int i = 0; instr[i]; i++)													//заполнение массива указателей позициями новых слов
	{																				//и подсчет количества слов в строке instr
		if (instr[i] != ' ' && instr[i + 1])
		{
			if (!inWord)
			{
				inWord = 1;
				pointers[wordCount++] = instr + i;
			}
		}
		else inWord = 0;
	}
	int k = 0;
	for (int i = 0; i < wordCount; i++)
	{
		char WordBuf[BUF_WORD_SIZE] = { 0 };
		int j = 0;
		mixChars(pointers[i], WordBuf);												//заполнение WordBuf словом с перемешанными символами
		while (WordBuf[j])															//занесение WordBuf в outstr
		{
			outstr[k++] = WordBuf[j];
			j++;
		}
		outstr[k++] = ' ';
	}
	outstr[k-1] = '\0';
	return outstr;
}