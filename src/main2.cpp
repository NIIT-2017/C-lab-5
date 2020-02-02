#include "task2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 8

int main()
{
    char arr[M][M];

    while (1)
    {
        clearMatrix(arr);
        fillMatrix(arr);
        setMatrix(arr);
        system("cls");
        printMatrix(arr);
        clock_t begin = clock();
        while (clock() < begin + CLOCKS_PER_SEC * 2);
    }
    
    return 0;
}