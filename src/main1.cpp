#include"task1.h"
#define N 256

int main()
{
    char in[N] = { 0 };
    char out[N] = { 0 };
    printf("enter a line\n");
    fgets(in, N, stdin);
    if (in[strlen(in) - 1] == '\n')
        in[strlen(in) - 1] = '\0';
    printf("%s\n", randomWords(in, out));
    return 0;
}