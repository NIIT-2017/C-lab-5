#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15
#define C 32

char *mixChars(char *in, char *out)
{
	int i = 0, j =0, k=0;
	char temp = { NULL };
	while (*in && *in != ' ')
		out[i++] = *in++;
	out[i] = '\0';
	if (out[i-1] == '\n') // убираем \n, если он попадает внутрь слова
		out[i-1] = '\0';
	if (i < 4) // если в слове от 1-го до 3-х символов, то...
		return out; // ...возвращаем слово без изменений
	else if (i == 4) // если в слове 4 символа, то...
	{
		temp = out[1];
		out[1] = out[2];
		out[2] = temp; // ...меняем 2-й и 3-й местами (1-й и 2-й элементы массива)
		return out; // возвращаем измененное слово
	}
	else if (i > 4)
	{
		int iteration = strlen(out)+1;
		for (i = 0; i < iteration; i++)
		{
			j = 1 + rand() % (strlen(out) - 2);
			k = 1 + rand() % (strlen(out) - 2);
			while (j == k) // исключаем ложное тасование
				k = 1 + rand() % (strlen(out) - 2);
			temp = out[j];
			out[j] = out[k];
			out[k] = temp;
		}
		return out;
	}
}
char *mixLine(char *instr, char * outstr)
{
	int i = 0, j = 0, count = 0;
	char in[C] = { NULL };
	while (instr[i] != '\0') // передаем адреса первых символов каждого слова в массив указателей
	{
		if (instr[i] != ' ' && instr[i] != '\0') // находим первый символ слова
		{
			char out[C] = { NULL }; // объявляем массив для возвращения из ф-ии "mixChars" слова
			char *p = &instr[i]; // указатель на 1-й символ слова
			mixChars(p, out); // вызываем ф-ию для перемешивания символов в слове
			for (int k = 0; out[k] != '\0'; k++, j++)
				outstr[j] = out[k]; // переписываем полученное слово в строку для вывода
			outstr[j] = ' ';
			j++;
			while (instr[i] != ' ' && instr[i] != '\0')
				i++;
			i--;
		}
		i++;
	}
	outstr[j-1] = '\0'; 
	return outstr;
}