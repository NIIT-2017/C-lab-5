#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "task2.h"

#define SIZE 10

int main()
{
    srand(time(NULL));
    
    char matr[SIZE][SIZE];

    while (1)
    {
        clearMatrix(matr);
        fillMatrix(matr);
        setMatrix(matr);
        printMatrix(matr);
        printf("\n");
        Sleep(1000);
    }

    return 0;
}