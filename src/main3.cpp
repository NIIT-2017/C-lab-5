/*
 Написать программу, переставляющую случайным образом симво-
 лы каждого слова каждой строки текстового файла, кроме первого
 и последнего, то есть начало и конец слова меняться не должны.
 Пояснение
 
 Программа открывает существующий тектстовый файл и читает его построчно. Для каждой строки выполняется разбивка на слова и независимая обработка каждого слова
 
 Состав
 
 Программа должна состоять из функций:
 
 - char *mixChars(char *in, char *out) -  перемешивание символов в одном слове
 - char *mixLine(char *instr, char * outstr) - перемешивание для целой строки
 - int main()
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

#define N 20
#define M 256

int main (){
    
    char arr[N][M] = {'\0'}; // массив в который считываем содержание файла
    char outstr[M] = {'\0'}; // массив с перемешанной строкой
    
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
        fgets(arr[strNumber], M, fp);
        mixLine(arr[strNumber], outstr); // передаем полученный массив в в функцию обработки строки
        fprintf(fpW, "%s\n", outstr);
        strNumber++;
    }
    
    fclose(fp);
    fclose(fpW);
    
    return 0;
}
