#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 256

char* randomWords(char* in, char* out)
{
	srand(time(NULL));
	char* arr[SIZE];
	int i = 0; //счётчик символов в массиве
	int j = 0;
	int n = 0; //счётчик для определения длинны записываемой строки
	char* S; //указатель на счётчик слов
	int inWord = 0; //пробол - не пробел	
	char* element = out;
	while (*in)//функция считывания строк и записывания их в массив
	{
		if (*in != ' ' && inWord == 0) //если нашли слово
		{
			arr[i] = in; //запись первого символа в массиве указателя
			i++;
			inWord = 1;
			n++;
		}
		else if (*in == ' ' && inWord == 1) //если словов закончилось
		{
			inWord = 0;
		}
		in++; //переход к следующему элементу в массиве указателя
	}
	for (i = n - 1; i >= 1;  i--) //перемешывание массива
	{		
		j = rand() % (i + 1);
		S = arr[j];
		arr[j] = arr[i];
		arr[i] = S;			
	}
	for (j = 0; j < n; j++) //вывод полученного массива
	{
		S = arr[j];
		while (*S != ' ' && *S != '\0')
		{
			*out = *S;
			S++;
			out++;
		}
		*out = ' ';
		out++;
	}
	out--;
	*out = 0;
	return element;
}

