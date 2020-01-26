#include "task2.h"

void clearMatrix(char(*arr)[M])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            arr[i][j] = SYMBOL_OF_VOID;
}
void fillMatrix(char(*arr)[M])
{
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0, r = 0; j < M / 2; j++)
        {
            r = rand() % 2;
            if (r == 1)
                arr[i][j] = PRINTING_SYMBOL;
        }
    }
}
void setMatrix(char(*arr)[M])
{
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < M / 2; j++)
        {
            if (arr[i][j] == PRINTING_SYMBOL)
            {
                arr[i][M - 1 - j] = PRINTING_SYMBOL;
                arr[N - 1 - i][j] = PRINTING_SYMBOL;
                arr[N - 1 - i][M - 1 - j] = PRINTING_SYMBOL;
            }
        }
    }
}
void printMatrix(char(*arr)[M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%c", arr[i][j]);
        puts("");
    }
}