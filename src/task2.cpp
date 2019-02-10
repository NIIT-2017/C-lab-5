#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 41
#define M 41

void clearMatrix(char (* arr)[M]) //- заполнение двумерного массива (матрицы) пробелами (указатель arr на массив из M значений типа char)
{
    for(int x = 0; x < N; x++)
        for(int y = 0; y < M; y++)
            arr[x][y] = ' ';
}

void fillMatrix(char (* arr)[M]) // - заполнение верхнего левого квадранта матрицы звездочками
{
    srand(time(0));
    for(int x = 0; x < N/2; x++)
        for(int y = 0; y < M/2; y++)
        {
            if(rand()%3 == 1)
                arr[x][y] = '*';
        }
}

void setMatrix(char (* arr)[M]) // - копирование элементов в другие области матрицы
{
    for(int x = 0; x < N/2; x++)
        for(int y = 0; y < M/2; y++)
            arr[x][y] = arr[x][M-y-1] = arr[N-x-1][y] = arr[N-x-1][M-y-1] = arr[x][y]; // переприсваиваем координаты звёздочки по всем квадрантам
}

void printMatrix(char (* arr)[M]) // - печать матрицы
{
    for(int x = 0; x < N; x++)
    {
        for(int y = 0; y < M; y++)
            putchar(arr[x][y]);
            putchar('\n');
    }
}
