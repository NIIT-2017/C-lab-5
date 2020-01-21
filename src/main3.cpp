#include "task3.h"
#include <time.h>
int main()
{
    srand(time(NULL));
    FILE* fileIN = fopen("Data.txt", "r");
    int linesNumber;
    char **lines= readFile(fileIN,&linesNumber);
    fclose(fileIN);
    FILE* fileOut = fopen("Output.txt", "w");
    char buf[100];
    for (int i = 0; i < linesNumber; i++)
    {
        mixLine(lines[i], buf);
        fprintf(fileOut,"%s",buf);
    }
    return 0;
}