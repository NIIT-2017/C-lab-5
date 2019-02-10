#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"

#define N 128

int main()
{
    srand(time(0));
    FILE *fp;
    char instr[N] = {0}, outstr[N] = {0};
    fp = fopen("lab5.txt", "r");

    if (fp == NULL)
        {
            puts("File not found!");
            return 1;
        }

    while(fgets(instr, N, fp) !=NULL)
        puts(mixLine(instr, outstr));

    fclose(fp);
    return 0;
}
