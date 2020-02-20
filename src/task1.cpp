#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task1.h"
#define SIZE 256

char* randomWords(char* in, char* out)
{
char* buf[SIZE] = { 0 };
int InWord = 0;
int i = 0, j = 0, count = 0;

if (in[strlen(in) - 1] == '\n')
in[strlen(in) - 1] = '\0';

while (in[i])
{
    if (in[i] != ' ' && InWord == 0)
    {/* начало слова*/
        InWord = 1;
        buf[count] = &in[i];
        count++; 
        i++;
    }
    else if (in[i] != ' ' && InWord == 1)
    {/* в слове*/
        i++;
    }
    else if (in[i] == ' ' && InWord == 1)
    {/* конец слова*/
        InWord = 0;
        i++;
    }
    
}
srand(time(NULL));
i = count - 1;
while(i >= 1)
{
    int j = 1 + rand() % (i + 1) - 1;

    char* tmp = buf[j];
    buf[j] = buf[i];
    buf[i] = tmp;
    i--;
}
i = 0, j = 0;
while( i < SIZE)
{
    char* letter = buf[j];
    while (letter && *letter != ' ' && *letter != '\0')
    {
        out[i++] = *letter++;
    }
    out[i++] = ' ';
    j++;
}
out[i] = '\0';
return out;
}