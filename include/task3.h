#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* mixChars(char* in, char* out);
char* mixLine(char* instr, char* outstr);
char** readFile(FILE* file, int* linesNumber);