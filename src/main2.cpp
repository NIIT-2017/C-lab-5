#include"task2.h"
#define M 10

int main()
{
    char arr[M][M];
    while (1) 
    {
        clearMatrix(arr); 
        fillMatrix(arr);
        setMatrix(arr); 
        printMatrix(arr); 
        clock_t begin = clock();
        while (clock() < begin + CLOCKS_PER_SEC);
        system("cls");
    }
    return 0;
}