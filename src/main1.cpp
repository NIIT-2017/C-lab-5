#include "task1.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char in[256];
    char out[256];

    printf("Enter a string\n");
    fgets(in, 256, stdin);
    if (*in != 0 && in[strlen(in) - 1] == '\n')
        in[strlen(in) - 1] = '\0';

    randomWords(in, out);

    puts(out);

    return 0;
}