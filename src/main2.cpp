#include "task2.h"
#include <stdlib.h>
#include <time.h> 
#define N 12 
#define M 12 

int main()
{
    char arr[N][M] = { {0} };
    while (1)
    {
        clearMatrix(arr);
        fillMatrix(arr);
        setMatrix(arr);
        system("cls");
        printMatrix(arr);
        clock_t begin = clock();
        while (clock() < begin + CLOCKS_PER_SEC);
    }
}