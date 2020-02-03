#include "task1.h"
char** readfile(FILE* file, int* linesNumber)
{
    int count = 0;
    char buf;
    while (fread(&buf, sizeof(char), 1, file))
    {
        if (buf == '\n')
            count++;
    }
    *linesNumber = count;
    char** lines = (char**)malloc(count * sizeof(char*));
    rewind(file);
    for (int i = 0; i < count; i++)
    {
        int lineLen = 0;
        do
        {
            fread(&buf, sizeof(char), 1, file);
            lineLen++;
        } while (buf != '\0' && buf != '\n');
        lineLen++;
        lines[i] = (char*)malloc(lineLen * sizeof(char));
        fseek(file, ftell(file) - lineLen, SEEK_SET);
        fgets(lines[i], 100, file);
    }
    return lines;
}

int main()
{
    srand(time(NULL));
    FILE* fileIn = fopen("Data.txt", "r");
    int linesNumber;
    char** lines = readfile(fileIn, &linesNumber);
    for (int i = 0; i < linesNumber; i++)
    {
        char* buf = (char*)malloc(sizeof(char) * strlen(lines[i]));
        randomWords(lines[i],buf);
        printf("%s\n",buf);
    }
    return 0;
}