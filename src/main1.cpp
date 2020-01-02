#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "task1.h"

int main()
{
    char in[size] = { 0 };
    char out[size] = { 0 };
    printf("Enter a line ");
    fgets(in, size, stdin);
    if (in[strlen(in) - 1] == '\n')
        in[strlen(in) - 1] = '\0';
    randomWords(in, out);
    printf("%s\n", out);
    return 0;
}