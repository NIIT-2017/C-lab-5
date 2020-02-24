#include"task3.h"
#define N 256

int main()
{
    char inarr[N];
    char outarr[N];
    time_t now;
    time(&now);
    srand(now);
    FILE* read = fopen("bookread.txt", "rt");
    FILE* rec = fopen("bookrec.txt", "wt");
    if (read == NULL)
    {
        puts("File open erorr!\n");
        return 0;
    }
    while (fgets(inarr, N, read) != NULL)
    {
        if (inarr[strlen(inarr) - 1] == '\n')
            inarr[strlen(inarr) - 1] = '\0';
        printf("%s\n", mixLine(inarr, outarr));
        fprintf(rec, "%s\n", mixLine(inarr, outarr));          
    }
    fcloseall();
    return 0;
}