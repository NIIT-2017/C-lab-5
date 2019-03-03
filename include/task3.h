#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define WORDS 512

char *mixChars(char *in, char *out);						//Перемешивание символов в одном слове
char *mixLine(char *instr, char * outstr);					//Перемешивание для целой строки