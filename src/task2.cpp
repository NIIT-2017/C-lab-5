#include "task2.h"
#include <time.h> 
#include <stdlib.h>
#include <stdio.h>

void clearMatrix(char(*arr)[M])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = ' ';
        }
}

void fillMatrix(char(*arr)[M])
{
    int number = 0;
    srand(time(NULL));
    for (int i = 0; i < (N/2); i++)
        for (int j = 0; j < (M/2); j++)
        {
            number = rand() % 2;
            if (number == 0)
            {
                arr[i][j] = '*';
            }
        }
}

void setMatrix(char(*arr)[M])
{
    for (int i = 0; i < (N / 2); i++)
        for (int j = 0; j < (M / 2); j++)
        {
            arr[i + (N / 2)][j] = arr[i][j];
        }
    for (int i = 0; i < (N / 2); i++)
        for (int j = 0; j < (M / 2); j++)
        {
            arr[i][j+(M/2)] = arr[i][j];
        }
    for (int i = 0; i < (N / 2); i++)
        for (int j = 0; j < (M / 2); j++)
        {
            arr[i + (N / 2)][j + (M / 2)] = arr[i][j];
        }
}

void printMatrix(char(*arr)[M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%c ", arr[i][j]);
        putchar('\n');
    }
}
