#include <stdio.h>
#include "task3.h"

#define N 128

int main()
{
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
