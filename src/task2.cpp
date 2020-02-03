#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"


void clearMatrix(char (* arr)[M])  { //заполнение двумерного массива (матрицы) пробелами
    for (int i=0; i<M; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = ' ';
        }
    }
}

void fillMatrix(char (* arr)[M]) { //заполнение верхнего левого квадранта матрицы звездочками
int leftHeight = M/2;
time_t now;
time(&now);
srand(now);
    for (int i=0; i<leftHeight; i++) {
        for (int j = 0; j < leftHeight; j++) {
            if (rand() % 2) {
                arr[i][j] = '*';
            }
        }
    }
}

void setMatrix(char (* arr)[M]) { // копирование элементов в другие области матрицы
int leftHeight = M/2;

    for (int i = 0; i < leftHeight; i++) {
        for (int j = 0; j< leftHeight; j++) {
            arr[M-1-i][j] = arr[i][j];
            arr[M-1-i][M-1-j] = arr[i][j];
            arr[i][M-1-j] = arr[i][j];
        }
    }
}

void printMatrix(char (* arr)[M]) {
    for (int i = 0; i<M; i++) {
        for (int j = 0; j < M; j++)
            printf("%3c", arr[i][j]);
        puts("");
    }

}
