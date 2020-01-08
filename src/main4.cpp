#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task1.h"

#define N 1024

int main()
{
    srand(time(NULL));
    
    char in[N];
    char out[N];
    
    FILE * fp;
    fp = fopen("strings.txt", "rt");

    if (fp == NULL)
    {
        puts("File open error!");
        return 1;
    }

    while (fgets(in, N, fp) != NULL)
    {
        if (in[strlen(in) - 1] == '\n')
            in[strlen(in) - 1] = '\0';
        printf("%s\n", randomWords(in, out));
    }

    fclose(fp);

    return 0;
}