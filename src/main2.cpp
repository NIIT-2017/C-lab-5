#include "task2.h"
int main()
{
    srand(time(NULL));
    char arr[M][M];
    while (1)
    {
        clearMatrix(arr);
        fillMatrix(arr);
        setMatrix(arr);
        system("cls");
        printMatrix(arr);
        _sleep(50);
    }
    return 0;
}