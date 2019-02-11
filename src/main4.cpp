/*
 Задача №4
 
 Написать программу, которая читает построчно текстовый файл и
 переставляет случайно слова в каждой строке
 Пояснение
 
 Программа открывает существующий тектстовый файл и читает его построчно. Для каждой строки вызывается функция, разработанная в рамках задачи 1.
 
 - char * randomWords(char * in, char *out) - функция, изменяющая порядок слов из in и записывающую их в out
 - int main()
 */
#include <stdio.h>
#include <string.h>
#include "task1.h"

int main() {
    
    char in[30][256] = {'\0'};
    char out[256] = {'\0'};
    
    FILE * fp = NULL;
    fp = fopen("text.txt", "r+");
    
    if (fp == NULL){
        printf("Your file can not be find\n");
        return 1;
    }
    
    FILE * fpW = NULL;
    fpW = fopen("myfile.txt", "w");
    
    if (fpW == NULL){
        printf("Your file can not be find\n");
        return 1;
    }
    
    
    int strNumber = 0; // номер строки в файле
    while(!feof(fp)){
        fgets(in[strNumber], 256, fp);
        randomWords(in[strNumber], out);
        fprintf(fpW, "%s\n", out);
        for(int i = 0; i < strlen(out); i++)
            out[i] = '\0';
        strNumber++;
    }
    fclose(fp);
    fclose(fpW);
    
    
    
    return 0;
}
