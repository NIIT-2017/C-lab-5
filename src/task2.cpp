#include "task2.h"
void clearMatrix(char(*arr)[M])
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            arr[i][j] = ' ';
}
void fillMatrix(char(*arr)[M])
{
    int N = M / 2;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (rand() % 3 == 0)
                arr[i][j] = '*';
}
void setMatrix(char(*arr)[M])
{
    int N = M / 2;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            arr[M-1-i][j] = arr[i][j];
            arr[M-1 - i][M-1-j] = arr[i][j];
            arr[i][M-1-j] = arr[i][j];
        }
}
void printMatrix(char(*arr)[M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}