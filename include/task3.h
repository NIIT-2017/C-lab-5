//Clab5 task3

/*Написать программу, переставляющую случайным образом символы каждого слова каждой строки 
текстового файла, кроме первого и последнего, то есть начало и конец слова меняться не должны.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 256

char* mixChars(char* in, char* out);		// перемешивание символов в одном слове
char* mixLine(char* instr, char* outstr);	// перемешивание для целой строки