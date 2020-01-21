#include "task1.h"
#include "task3.h"
int main()
{
    srand(time(NULL));
    FILE* fileIn = fopen("Data.txt", "r");
    int linesNumber;
    char** lines = readFile(fileIn, &linesNumber);
    for (int i = 0; i < linesNumber; i++)
    {
        char* buf = (char*)malloc(sizeof(char) * strlen(lines[i]));
        randomWords(lines[i],buf);
        printf("%s\n",buf);
    }
}