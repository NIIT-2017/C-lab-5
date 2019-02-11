//
//  task2.cpp
//  _C-lab-5
//
//  Created by Антон Петров on 09/02/2019.
//  Copyright © 2019 Антон Петров. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "stdlib.h"
#include "task2.h"

// фунуция очищает матрицу заменяя все символы в ней на пробелы
void clearMatrix(char (* arr)[M]){
    for (int i = 0; i < M; i++){
        for(int j = 0; j < M; j++)
            arr[i][j] = ' ';
    }
}
// заполняем верхний левый квадрант
void fillMatrix(char (* arr)[M]){
    srand(time(0));
    for(int i = 0; i < M/2; i++){
        for(int j = 0; j < M/2; j++){
            int flag = 0; // флаг: 0 - пробел, 1 - звездочка. Нужен для удобства дебага
            flag = rand() % 2;
            if (flag == 1)
                arr[i][j] = '*';
            else
                arr[i][j] = ' ';
        }
    }
}
// смметрично построчно копируем значения первого квадранта в остальные
void setMatrix(char (* arr)[M]){
// заполняем верхнюю правую часть
    int i = 0; // номера строчек
    int j = 0; // номера символов в строчке
    for(int i = 0; i <= (M/2 - 1); i++){
        while(j < (M/2 - 1)){
            arr[i][M/2 + j] = arr[i][(M/2 - 1) - j];
            j++;
        }
        j = 0; // обнуляем номер символа, чтобы новую строчку начать считывать сначала
    }
// копируем верхнее полуквадратие в нижнее полуквадратие
while(i <= (M/2 -1)){
        while(j < M){
            arr[M-1-i][j] = arr[i][j];
            j++;
        }
        j = 0;
        i++;
    }

}
// печать матрицы
void printMatrix(char (* arr)[M]){
    for (int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            printf("%c", arr[i][j]);
            if(j == M-1)
                printf("\n");
        }
    }
}

void clrscr(void)
{
    printf("\033[2J"); /* Clear the entire screen. */
    printf("\033[0;0f"); /* Move cursor to the top left hand corner*/
}
