#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task3.h"
#define size 256

int main()
{
    char instr[size] = { 0 };
    char outstr[size] = { 0 };
    FILE* fp;
    fp = fopen("file.txt", "rt");
    if (!fp)
    {
        puts("Error!");
        return 1;
    }
    while (fgets(instr, size, fp))
    {
        mixLine(instr, outstr);
        printf("%s", outstr);
    }
    fclose(fp);
    return 0;
}