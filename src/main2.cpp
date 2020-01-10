#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task2.h"

#define SIZE 10

int main()
{
    srand(time(NULL));
    
    char matr[SIZE][SIZE];

    while (1)
    {
        system("cls");
        clearMatrix(matr);
        fillMatrix(matr);
        setMatrix(matr);
        printMatrix(matr);
        printf("\n");
        clock_t begin = clock();
        while (clock() < begin + CLOCKS_PER_SEC);
    }

    return 0;
}