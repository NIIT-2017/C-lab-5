#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 16					//Количество символов в строке
#define N 16					//Количество строк

void clearMatrix(char(*arr)[M]);
void fillMatrix(char(*arr)[M]);
void setMatrix(char(*arr)[M]);
void printMatrix(char(*arr)[M]);