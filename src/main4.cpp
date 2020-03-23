#pragma warning(disable : 4996)
#include "task1.h"
#include <stdio.h>
#include <string.h>
#define SIZE 256

int main()
{
	char in[SIZE];
	char out[SIZE];
	FILE* fp;
	fp = fopen("text.txt", "rt");
	if (fp == NULL)
	{
		puts("File open erorr!");
		return 1;
	}
	while (fgets(in, SIZE, fp) != 0 && *in != '\n')
	{
		if (in[strlen(in) - 1] == '\n') //считывание начала строки
		{
			in[strlen(in) - 1] = 0; //удаление \n
		}
	}
	fclose(fp);
	printf("%s", randomWords(in, out));
	return 0;
}