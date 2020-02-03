#include "task1.h"
int countWords(char* str, int len)
{
    int count = 0;
    for (int i = len; i > 0; i--)
        if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\0') && (str[i - 1] != ' '&&str[i-1]!='\n'))
            count++;
    return count;
}
char* randomWords(char* in, char* out)
{
    int len = strlen(in);
    int wordsNumber = countWords(in, len);
    char** positions = (char**)malloc(wordsNumber * sizeof(char*));
    int currentWord = 0;
    if (in[0] != ' ')
    {
        positions[0] = &in[0];
        currentWord++;
    }
    for (int i = 0; i < len-1; i++)
    {
        if (in[i] == ' ' && in[i + 1] != ' ')
        {
            positions[currentWord] = &in[i + 1];
            currentWord++;
        }
    }
    int* sequence = (int*)malloc(wordsNumber * sizeof(int));
    int outPos = 0;
    for (int i = 0; i < wordsNumber; i++)
    {
        while (1)
        {
            sequence[i] = rand() % wordsNumber;
            int repeat = 0;
            for (int j = 0; j < i; j++)
            {
                if (sequence[j] == sequence[i])
                {
                    repeat = 1;
                    break;
                }
            }
            if (!repeat)
                break;
        }
        char currentChar = positions[sequence[i]][0];
        for (int j = 1; currentChar!=' '&& currentChar != '\0'&&currentChar != '\n'; j++)
        {
            out[outPos] = currentChar;
            currentChar = positions[sequence[i]][j];
            outPos++;
        }
        out[outPos] = ' ';
        outPos++;
    }
    out[outPos-1] = '\0';
    return out;
}