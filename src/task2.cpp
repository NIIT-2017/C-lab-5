#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 8

void clearMatrix(char(*arr)[M])
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            arr[i][j] = ' ';
}

void fillMatrix(char(*arr)[M])
{
    srand(time(NULL));

    for (int i = 0; i < M / 2; i++)
        for (int j = 0; j < M / 2; j++)
        {
            if (rand() % 2)
                arr[i][j] = '*';
        }
}

void setMatrix(char(*arr)[M])
{
    for (int i = 0; i < M / 2; i++)
        for (int j = M / 2; j < M; j++)
            arr[i][j] = arr[i][M - 1 - j];

    for (int i = 0; i < M / 2; i++)
        for (int j = 0; j < M; j++)
            arr[M - 1 - i][j] = arr[i][j];
}

void printMatrix(char(*arr)[M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
            putc(arr[i][j], stdout);
        putc('\n', stdout);
        clock_t begin = clock();
        while (clock() < begin + CLOCKS_PER_SEC);
    }
}