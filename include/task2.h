#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void clearMatrix(char(*arr)[SIZE]); //заполнение двумерного массива(матрицы) пробелами
void fillMatrix(char(*arr)[SIZE]);  //заполнение верхнего левого квадранта матрицы звездочками
void setMatrix(char(*arr)[SIZE]);   //копирование элементов в другие области матрицы
void printMatrix(char(*arr)[SIZE]); //печать матрицы
