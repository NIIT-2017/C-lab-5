#include"task1.h"

#define N 256
int main()
{
    char in[N];
    char out[N];
    FILE* read = fopen("bookread.txt", "rt");
    FILE* rec = fopen("bookrec.txt", "wt");
    if (read == NULL)
    {
        puts("File open erorr!\n");
        return 0;
    }
    while (fgets(in, N, read) != NULL)
    {
        if (in[strlen(in) - 1] == '\n')
            in[strlen(in) - 1] = '\0';
        printf("%s\n", randomWords(in, out));
        fprintf(rec, "%s\n", randomWords(in, out));
    }
    fcloseall();
    return 0;
}