#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillMatrix(char(*m)[SIZE])
{
    for (int i = 0; i < SIZE / 2; i++)
    for (int j = 0; j < SIZE / 2; j++)
    if (rand() % 2)
        m[i][j] = '*';
}

void setMatrix(char(*m)[SIZE])
{
    for (int i = 0; i < SIZE / 2; i++)
        for (int j = 0; j < SIZE / 2; j++)
            m[i][SIZE - 1 - j] = m[i][j];

    for (int i = 0; i < SIZE / 2; i++)
        for (int j = 0; j < SIZE; j++)
            m[SIZE - 1 - i][j] = m[i][j];
}

void printMatrix(char(*m)[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%c ", m[i][j]);
        printf("\n");
        clock_t begin = clock();
        while (clock() < begin + CLOCKS_PER_SEC / 4);
    }
}

void clearMatrix(char(*m)[SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            m[i][j] = ' ';
}