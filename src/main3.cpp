#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "task3.h"

#define N 1024 // max length of string

int main()
{
    setlocale(LC_ALL, "Russian");
    
    srand(time(NULL));
    
    char instr[N];
    char outstr[N];

    FILE *fp;
    fp = fopen("strings.txt", "rt");

    if (fp == NULL)
    {
        puts("File open error!\n");
        return 1;
    }
    
    while (fgets(instr, N, fp) != NULL)
    {
        if (instr[strlen(instr) - 1] == '\n')
            instr[strlen(instr) - 1] = '\0';
        printf("%s\n", mixLine(instr, outstr));
    }

    fclose(fp);

    return 0;
}