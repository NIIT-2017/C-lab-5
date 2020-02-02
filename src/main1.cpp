#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

#define N 128 // max length of string

int main()
{
    srand(time(NULL));

    char in[N];
    char out[N];

    printf("Enter a line:\n");
    fgets(in, N, stdin);

    if (in[strlen(in) - 1] == '\n')
        in[strlen(in) - 1] = '\0';

    printf("%s\n", randomWords(in, out));

    return 0;
}