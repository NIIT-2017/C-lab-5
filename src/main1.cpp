#include <stdio.h>
#include "task1.h"
#define SIZE 100
int main()
{
    srand(time(NULL));
    char in[SIZE],out[SIZE];
    fgets(in, SIZE, stdin);
    randomWords(in,out);
    printf(out);
    return 0;
}