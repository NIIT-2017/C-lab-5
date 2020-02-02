#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "task1.h"
#define size 256

int main()
{
    char in[size] = { 0 };
    char out[size] = { 0 };
    FILE* fp;
    fp = fopen("file.txt", "rt");
    if (!fp)
    {
        puts("Error!");
        return 1;
    }
    while (fgets(in, size, fp))
    {
        if (in[strlen(in) - 1] == '\n')
            in[strlen(in) - 1] = '\0';
        randomWords(in, out);
        printf("%s\n", out);
    }
    fclose(fp);
    return 0;
}