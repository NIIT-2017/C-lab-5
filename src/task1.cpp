#include <string.h>
#include <stdlib.h>
#include <time.h>

void writeWords(int numberOfWords, char** p, char* out)
{
    srand(time(NULL));
    int j = 0;
    int size = numberOfWords;
    for (int i = 0; i < numberOfWords; i++)
    {
        int k = 0;
        int randNum = rand() % size;
        while (*(p[randNum] + k) != ' ' && *(p[randNum] + k) != 0)
        {
            out[j] = *(p[randNum] + k);
            k++;
            j++;
        }
        out[j] = ' ';
        j++;
        p[randNum] = p[size - 1];
        size--;
    }
    out[j] = '\0';
}

char* randomWords(char* in, char* out)
{
    char* p[32];

    int flag = 0;
    int numberOfWords = 0;
    for (int i = 0; i < strlen(in); i++)
    {
        if (*in == 0)
        {
            break;
        }
        if (in[i] != ' ' && flag == 0)
        {
            p[numberOfWords] = &in[i];
            flag = 1;
            numberOfWords++;
        }
        if (in[i] == ' ' && flag)
        {
            flag = 0;
        }
    }
    writeWords(numberOfWords, p, out);

    return out;
}