#include"task1.h"

#define N 256

char* randomWords(char* in, char* out)
{
    time_t now;
    time(&now);
    srand(now);
    char* parr[N] = { 0 };
    int i = 0;
    int j = 0;
    int inword = 0;
    while (in[i])
    {
        if (in[i] != ' ' && inword == 0)
        {
            parr[j] = &in[i];
            inword = 1;
            j++;
        }
        else if (in[i] == ' ' && inword == 1)
            inword = 0;
        i++;
    }
    for (int k = j; k > 1; k--)
    {
        int random = rand() % k;
        char* m = parr[k - 1];
        parr[k - 1] = parr[random];
        parr[random] = m;
    }
    i = 0;
    j--;
    while (j >= 0)     //filling in an array "OUT"
    {
        while (*parr[j] != '\0' && *parr[j] != ' ')
        {
          out[i] = *parr[j];
          parr[j]++;          
          i++;
        }
        out[i] = ' ';
        i++;
        j--;
    }
    out[i - 1] = '\0';
    return out;
}