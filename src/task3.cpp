#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define W 64 // max number of words
#define S 32 // max number of symbols in word

char *mixChars(char *in, char *out)
{
    int len = 0; // length of word
    for (int i = 0; i < S; i++)
    {
        if (*(in + i) == ' ' || *(in + i) == '\n' || *(in + i) == '\0') break;
        len++;
    }
    
    int flag = 1;
    int pool[S] = {-1}; // array for random digits
    int * p = pool;

    // fill array with random digits

    for (int j = 0; j < len - 2; j++)
    {
        do
        {
            *(p + j) = 1 + rand() % (len - 2);
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
    
    // put symbols in "out" according to positions in random array

    int m = 0, n = 0;

    while (m < len)
    {
        if (m == 0 || m == len - 1)
        {
            *(out + m) = *(in + m);
            m++;
            continue;
        }
        *(out + m) = *(in + *p);
        m++;
        p++;
    }

    *(out + len) = '\0';

    return out;
}

char *mixLine(char * instr, char * outstr)
{
    int i = 0, inWord = 0, count = 0;
    char * w[W]; // array of pointers to words
    char out[S]; // array for mixed word
    
    while (*(instr + i))
    {
        if (*(instr + i) != ' ' && inWord == 0)
        {
            *(w + count) = instr + i;
            inWord = 1;
            count++;
        }
        else if (*(instr + i) == ' ' && inWord == 1)
            inWord = 0;
        i++;
    }
    
    char * r; // pointer to word with mixed symbols
    int j = 0, m = 0;
        
    while (m < count)
    {
        r = mixChars(*(w + m), out);
        for (int k = 0; k < strlen(r); k++)
        {
            if (*(r + k) == '\0') break;
            *(outstr + j) = *(r + k);
            j++;
        }
        *(outstr + j) = ' ';
        j++;
        m++;
    }

    if (outstr[strlen(instr)] == ' ')
        outstr[strlen(instr)] = '\0';

    return outstr;
}