/*Написать программу, которая читает построчно текстовый файл и переставляет случайно слова в каждой строке*/

#include "task1.h"

int main() {
	char str[WORDS];
	char buf[WORDS] = { '\0' };
	FILE *fp;

	puts("We use File: \"Lb5_sort4.txt\"");
	fp = fopen("Lb5_sort4.txt", "r");												//Открытие тестового файла в корневом каталоге
	fp == NULL ? puts("Opening is failed!") : puts("Opening is successful!");		//Проверка корректности открытия файла

	while (fgets(str, WORDS, fp) != NULL) {
		randomWords(str, buf);														//Мешаем слова в строке
		puts(buf);
		int i = 0;
		while (i < WORDS)
			buf[i++] = '\0';
	}

	if (fclose(fp) == EOF)
		puts("File \"Lb5_sort4.txt\" is not closed");
	return 0;
}