#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <clocale>

#define LEN_MAX 256
#define NLINES_MAX 7
#define WORD_LEN 32

char* mixChars(char* in, char* out);
char* mixLine(char* instr, char* outstr);
