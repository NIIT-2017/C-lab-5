#include "task2.h"
#include <time.h>

int main()
{
    char matrix[N][M] = { NULL };

    time_t now;
    time(&now);
    srand(now);
    for (int count = 0; count < TIME_OF_PRESENTATION; count++)
    {
        clearMatrix(matrix);
        fillMatrix(matrix);
        setMatrix(matrix);
        system("cls");
        printMatrix(matrix);
        clock_t begin = clock();
        while (clock() < begin + CLOCKS_PER_SEC / SPEED_OF_PRESENTATION);
    }
    return 0;
}
