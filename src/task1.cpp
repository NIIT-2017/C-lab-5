#include "task1.h"
#include <time.h> 
#include <stdlib.h>
#include <stdio.h>

char* randomWords(char* in, char* out)
{
    char* words[size] = { NULL };
    int InWord = 0;
    int i = 0, count = 0;
    while (in[i])
    {
        if (in[i] != ' ' && InWord == 0)//начало слова
        {
            InWord = 1;
            words[count] = &in[i];
            count++; //после последнего слова также увеличивается
            i++;
        }
        else if (in[i] != ' ' && InWord == 1)//в слове
        {
            i++;
        }
        else if (in[i] == ' ' && InWord == 1)//конец слова
        {
            InWord = 0;
            i++;
        }
    }
    srand(time(NULL));
    for (int i = count - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);

        char* tmp = words[j];
        words[j] = words[i];
        words[i] = tmp;
    }
    for (int i = 0, j = 0; i < size;j++)
    {
        char* symbl = words[j];
        while (symbl && *symbl != ' ' && *symbl != '\0')
        {
            out[i++] = *symbl++;
        }
        out[i++] = ' ';
    }
    out[i] = '\0';
    return out;
}
