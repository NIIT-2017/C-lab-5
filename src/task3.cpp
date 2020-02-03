#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* mixChars(char* in, char* out)
{
	int i = 1,
		p = 0,
		max = strlen(in) - 1,
		x = max;
	srand(time(NULL));
	out[0] = in[0];

	for (; i< max; i++, x--)
	{
		for ( ; in[p]; p++)
			in[p] = in[p + 1];
		p = rand() % (x-1);
		out[i] = in[p];
	}

	out[i++] = in[1];
	out[i]='\0';
	
	return out;
}

char* mixLine(char* instr, char* outstr)
{
	int inWord = 0, //флаг нахождения в слове
		count = 0, //счетчик количества букв
		u = 0;
	char buf[64], bufout[64];

	for (int i = 0; instr[i] != '\0'; i++) // сканиурем массив на слова
	{
		if (instr[i] != ' ' && inWord == 0)//только что вошли в слово
		{
			inWord = 1;
			buf[count++] = instr[i]; //начинаем записывать слово в отдельный массив
		}
		else if (instr[i] != ' ' && inWord == 1 && instr[i+1] != '\0') // находимся в слове
			buf[count++] = instr[i]; //продолжаем записывать слово в отдельный массив
		else if ((instr[i] == ' ' || instr[i] == '\0' || instr[i] == '\n') && inWord == 1)//вышли из слова
		{
			buf[count] = '\0';//запись слова окончена
			mixChars(buf, bufout); //миксуем буквы в слове
			for (int j = 0; j <= (count - 1); j++, u++) //записываем слово в выводимом массиве строки
				outstr[u] = bufout[j];
			outstr[u++] = ' ';
			inWord = 0;//обнуляем флаг нахожддения в слове
			count = 0; //обнуляем счетчик количества букв
		}
		else if (instr[i] != ' ' && inWord == 1 && (instr[i+1] == '\0' || instr[i+1] == '\n')) // последний символ в строке
		{
			buf[count++] = instr[i];
			buf[count] = '\0';//запись слова окончена
			mixChars(buf, bufout); //миксуем буквы в слове
			for (int j = 0; j <= (count - 1); j++, u++) //записываем слово в выводимом массиве строки
				outstr[u] = bufout[j];
		}
	}
	outstr[u] = '\0';
	return outstr;
}