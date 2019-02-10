#include <stdio.h>
#include "task3.h"

#define N 128

int main()
{
    FILE *fp;
    char instr[N] = {0}, outstr[N] = {0};
    fp = fopen("lab5.txt", "r+");

    while(fgets(instr, N, fp) !=NULL)
    {
        fputs(mixLine(instr, outstr), fp);
    }

    fclose(fp);
    return 0;
}

