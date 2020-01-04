#include <stdlib.h>
#include <string.h>

#define N 15 // max number of words

char * randomWords(char * in, char * out)
{
    int i = 0, inWord = 0, count = 0;
    char * s[N];
    
    while (*(in + i))
    {
        if (*(in + i) != ' ' && inWord == 0)
        {
            *(s + count) = in + i;
            inWord = 1;
            count++;
        }
        else if (*(in + i) == ' ' && inWord == 1)
            inWord = 0;
        i++;
    }
    
    int flag = 1;
    int pool[N] = { -1 }; // array for random digits
    int * p = pool;

    for (int j = 0; j < count; j++)
    {
        do
        {
            *(p + j) = rand() % count;
            flag = 0;
            for (int k = 0; k < j; k++)
            {
                if (*(p + j) == *(p + k))
                {
                    flag = 1;
                    break;
                }
            }
        } while (flag == 1);
    }

    int m = 0, n = 0;

    while (m < strlen(in))
    {
        for (int n = 0; n < strlen(s[*p]); n++)
        {
            if (*(s[*p] + n) == ' ') break;
            *(out + m) = *(s[*p] + n);
            m++;
        }
        *(out + m) = ' ';
        m++;
        p++;
    }

    if (out[strlen(in)] == ' ')
        out[strlen(in)] = '\0';

    return out;
}