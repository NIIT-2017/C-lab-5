#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "task2.h"

int main() {

    char matr[M][M];
    while (1) {
        clearMatrix(matr);
        puts("");
        fillMatrix(matr);
        puts("");
        printMatrix(matr);
        puts("");
        setMatrix(matr);
        puts("");
        printMatrix(matr);
        puts("");
        sleep(3);
        system("clear");
    }


    return 0;
}