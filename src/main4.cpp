//#include "C:\learning_ci\lab5\lab5task1\lab5task1\task1.cpp"
#include <stdio.h>
#include <string.h>
#include "task1.h"
#include "task1.cpp"

#define LINES 256
#define SYMBOLS_IN_LINE 256

void printLinesToFile(const char* str[], int size, FILE* fp)
{
    
    for (int i = 0; i < size; i++)
    {
        fprintf(fp, "%s\n", str[i]);
    }
}

int main()
{
    FILE* fp;

    fp = fopen("lines.txt", "rt");

    if (!fp)
    {
        puts("Error: file is not found");
        return 1;
    }

    int ch;
    int count_of_lines = 0;
    while ((ch = fgetc(fp)) != EOF)
        if (ch == '\n')
            count_of_lines++;
    
    rewind(fp);

    char lines_in[LINES][SYMBOLS_IN_LINE] = { 0 };
    char lines_out[LINES][SYMBOLS_IN_LINE] = { 0 };
    char* p[LINES] = { 0 };

    for (int i = 0; i < count_of_lines; i++)
    {
        fgets(lines_in[i], SYMBOLS_IN_LINE, fp);

        if (lines_in[i][strlen(lines_in[i]) - 1] == '\n')
            lines_in[i][strlen(lines_in[i]) - 1] = '\0';
        
        randomWords(lines_in[i], lines_out[i]);
        p[i] = lines_out[i];
    }

    fp = fopen("lines.txt", "at");
    fputs("\n", fp);

    printLinesToFile((const char**)p, count_of_lines, fp);

    fclose(fp);
    printf("File has been changed\n");

    return 0;
}
