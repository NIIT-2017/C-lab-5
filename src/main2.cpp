#include "task2.h"
#include <time.h>
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
        time_t  now = clock();
        while (now - clock() > CLOCKS_PER_SEC);
    }
    return 0;
}