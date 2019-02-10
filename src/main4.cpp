#include <stdio.h>
#include "task1.h"

#define N 128

int main()
{
    FILE *fp;
    char in[N] = {0}, out[N] = {0};
    fp = fopen("lab5.txt", "w");
    fprintf(fp, "my flat is not very big");
    freopen("lab5.txt", "a+", fp);
    fgets(in, N, fp);
    fputs(randomWords(in, out), fp);
    fclose(fp);
    return 0;
}
