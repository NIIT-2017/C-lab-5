#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "task3.h"

#define N 20
#define M 256

// функция перемашивает символы внутри слова
char *mixChars(char *in, char *out){
    //очищаем массив out
    for(int i = 0; i < strlen(out); i++){
        out[i] = '\0';
    }
    //сначала получаем указатели на первую и последнюю букву слова
    char * firstLetter = NULL; // начало слова
    char * lastLetter = NULL; // конец слова
    int w = 0; // счетчик букв в слове
    firstLetter = in;
    while(1){
        in++;
        if(*in == ' ' || *in == '\0'){
            lastLetter = (in - 1);
            break;
        }
        w++;
    }
    out[0] = *firstLetter;
    out[w] = *lastLetter;
    //заполняем массив out[] пропущенными буквами
    for(int i = 0; i<w; i++){
        out[i] = *firstLetter++;
    }
    //перемешиваем символы в массиве
    for(int i = 1, j = 0; i<w-1; i++){
        j = 1 + rand() % (lastLetter - firstLetter - 1);
        char symbol = '\0';
        symbol = out[j];
        out[j] = out[i];
        out[i] = symbol;
    }
    
        return out;
}

//функция принимает строку и возвращет с намешанными символами
char *mixLine(char *instr, char * outstr){
    //очищаем массив outstr
    for(int i = 0; i < M; i++)
        outstr[i] = '\0';
    
    // меняем последний символ в массиве на \0
    if(instr[strlen(instr) - 1] == '\n')
        instr[strlen(instr) - 1] = '\0';
    char out[N] = {'\0'}; // массив для перемешанного слова
    
    //создаем указатели на каждое слов
    int flag = 0; // в слове 1, не в слове 0 (для алгоритма конечного автомата)
    int wordCounter = 0; // счетчик слов в массиве
    char * words[N] = { NULL }; // массив указателей на начало слов
//делим на слова и мещаем символы внутри каждого слова. Делим на слова по алгоритму конечного автомата
    for(int i = 0, k = 0; instr[i] != '\0'; i++){
        if(instr[i] != ' ' && flag == 0){
            words[wordCounter] = &instr[i];
            flag = 1;
            mixChars(words[wordCounter], out);
            wordCounter++;
        }
        if(instr[i] == ' ' && flag == 1){
            flag = 0;
            for(int j = 0; out[j] != '\0'; j++){
                outstr[k] = out[j];
                k++;
                }
            outstr[k] = ' ';
            k++;
        }
        if (instr[i+1] == '\0' && flag == 1){
            for(int j = 0; out[j] != '\0'; j++){
                outstr[k] = out[j];
                k++;
            }
        } 
    }
    return outstr;

}

