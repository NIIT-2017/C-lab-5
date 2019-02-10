#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "task2.h"

#define N 41
#define M 41

int main()
{
    char arr[N][M];
    while(1)
    {
        clearMatrix(arr);
        fillMatrix(arr);
        setMatrix(arr);
        system ("cls");         //функция очистки консоли
        printMatrix(arr);
        sleep(2);
    }
    return 0;
}
