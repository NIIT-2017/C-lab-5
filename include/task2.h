#define N 20
#define M 40
#define PRINTING_SYMBOL '*'
#define SYMBOL_OF_VOID ' '
#define SPEED 10

#include <stdio.h>
#include <stdlib.h>

void clearMatrix(char(*arr)[M]);
void fillMatrix(char(*arr)[M]);
void setMatrix(char(*arr)[M]);
void printMatrix(char(*arr)[M]);