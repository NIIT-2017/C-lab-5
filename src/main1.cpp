#include "task1.h"

int main()
{
    char in[SIZE_OF_LINE];
    char out[SIZE_OF_LINE];

    printf("Input the line\n");
    fgets(in, SIZE_OF_LINE, stdin);
    if (in[strlen(in) - 1] == '\n')
        in[strlen(in) - 1] = '\0';

    //char in[SIZE_OF_LINE] = { "my flat is not very big" };

    randomWords(in, out);
    printf("New line:\n%s", out);

    return 0;
}






