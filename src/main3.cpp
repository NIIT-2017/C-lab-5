/* Написать программу, переставляющую случайным образом символы каждого слова каждой строки текстового файла,
кроме первого и последнего, то есть начало и конец слова меняться не должны.*/

#include "task3.h"

int main() {
	char str[WORDS];
	char buf[WORDS] = { '\0' };
	FILE *fp;
	
	puts("We use File: \"Lb5_sort3.txt\"");
	fp = fopen("Lb5_sort3.txt", "r");											//Открытие тестового файла в корневом каталоге
	if (fp == NULL)
		puts("Opening is failed");												//Проверка корректности открытия файла

	while (fgets(str, WORDS, fp) != NULL) {
		puts(mixLine(str, buf));												//Мешаем слова в строке и выводим на экран
		int i = 0;
		while (i < WORDS)
			buf[i++] = '\0';
	}

	if (fclose(fp) == EOF)
		puts("File \"Lb5_sort3.txt\" is not closed");
	return 0;
}