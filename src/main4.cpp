#define _CRT_SECURE_NO_WARNINGS

#include "C:\Users\agubin\source\repos\C-lab-5\Task1\task1.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char in[512];
    char out[512];
    FILE* rf;
    FILE* wf;
    int eof = 0;

    rf = fopen("C:\\Labs\\In.txt", "r");
    wf = fopen("C:\\Labs\\Out.txt", "w");

    while (!eof)
    {
        if (fgets(in, 512, rf))
        {
            if (*in != 0 && in[strlen(in) - 1] == '\n')
                in[strlen(in) - 1] = '\0';
            fputs(randomWords(in, out), wf);
            fputs("\n", wf);
        }
        else
            break;
        eof = feof(rf);
    }

    return 0;
}