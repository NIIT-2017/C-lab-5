#include"task2.h"
#define M 10

void clearMatrix(char(*arr)[M])
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            arr[i][j] = ' ';
}

void fillMatrix(char(*arr)[M])
{
    time_t now;
    time(&now);
    srand(now);
    for (int i = 0; i < M / 2; i++)
        for (int j = 0; j < M / 2; j++)
        {
            int flag = rand() % 2;
            if (flag == 1)
                arr[i][j] = '*';
        }
}

void setMatrix(char(*arr)[M])
{
    for (int i = 0; i < M / 2; i++)
        for (int j = 0; j < M / 2; j++)
        {
            arr[M - i - 1][M - j - 1] = arr[i][j];
            arr[M - i - 1][j] = arr[i][j];
            arr[i][M - j - 1] = arr[i][j];
        }
}

void printMatrix(char(*arr)[M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%c", arr[i][j]);
        putchar('\n');
    }

}