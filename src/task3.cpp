#include "task3.h"
#include <string.h>

#define IN_WORD 1
#define OUT_WORD 0
#define IN_AND_OUT_ARE_IDENTICAL 1
#define IN_AND_OUT_ARE_NOT_IDENTICAL 0
#define WORD_CAN_BE_CHANGED 0
#define WORD_CANNOT_BE_CHANGED 1


char* clean_buf(char* buf, int size)
{
    for (int i = 0; i < size; i++)
        buf[i] = NULL;
    return buf;
}

int word_status(char* word)
{
    int status = WORD_CANNOT_BE_CHANGED;
    if (strlen(word) <= 2 * NUMBER_OF_UNCHANGEABLE_CH + 1)
        status = WORD_CANNOT_BE_CHANGED;
    else
    {
        for (int i = NUMBER_OF_UNCHANGEABLE_CH + 1; i < strlen(word) - 1 - NUMBER_OF_UNCHANGEABLE_CH; i++)
        {
            if (status == WORD_CANNOT_BE_CHANGED && word[i] == word[i - 1])
                status = WORD_CANNOT_BE_CHANGED;
            else
                status = WORD_CAN_BE_CHANGED;
        }
    }
    return status;
}

char* mixChars(char* in, char* out)
{
    char* p = in;
    int count = 0;
    int flag = IN_AND_OUT_ARE_NOT_IDENTICAL;
    int i = 0;
    int size = strlen(in);

    while (i < size)
    {
        if ((i < NUMBER_OF_UNCHANGEABLE_CH) || (i > size - 1 - NUMBER_OF_UNCHANGEABLE_CH))
        {
            out[i] = *p;
        }
        else
        {
            do
                i = rand() % ((size - NUMBER_OF_UNCHANGEABLE_CH - 1) - NUMBER_OF_UNCHANGEABLE_CH + 1) + NUMBER_OF_UNCHANGEABLE_CH;
            while (out[i] != NULL && count <= size - 2 * NUMBER_OF_UNCHANGEABLE_CH);

            out[i] = *p;
            count++;

            if (out[i] == in[i])
                flag = IN_AND_OUT_ARE_IDENTICAL;
            else
                flag = IN_AND_OUT_ARE_NOT_IDENTICAL;

            i = NUMBER_OF_UNCHANGEABLE_CH;

            if (count == size - 2 * NUMBER_OF_UNCHANGEABLE_CH && flag == IN_AND_OUT_ARE_IDENTICAL)
            {
                clean_buf(out, size);

                mixChars(in, out);
            }
            if (count == size - 2 * NUMBER_OF_UNCHANGEABLE_CH)
                i = size - 1 - NUMBER_OF_UNCHANGEABLE_CH;
        }
        i++;
        p++;
    }
    return out;
}

char* mixLine(char* instr, char* outstr)
{
    if (instr[strlen(instr) - 1] == '\n')
        instr[strlen(instr) - 1] = '\0';

    char word_in[SYMBOLS_IN_LINE] = { NULL };
    char word_out[SYMBOLS_IN_LINE] = { NULL };
    int flag = OUT_WORD;
    int i = 0;
    int j = 0;
    while(i < strlen(instr))
    {
        if (flag == OUT_WORD && instr[i] != ' ')
        {
            flag = IN_WORD;
            j = 0;
            word_in[j] = instr[i];
            j++;
        }
        else if (flag == IN_WORD && instr[i] != ' ')
        {
            word_in[j] = instr[i];
            j++;
        }
        else if (flag == IN_WORD && instr[i] == ' ')
        {
            flag = OUT_WORD;
            outstr[i] = instr[i];
            word_in[j] = '\0';
            i -= strlen(word_in);
            j = 0;
            
            if (word_status(word_in)==WORD_CANNOT_BE_CHANGED)
            {
                while (j < strlen(word_in))
                    outstr[i++] = word_in[j++];
            }
            else
            {
                clean_buf(word_out, SYMBOLS_IN_LINE);
                mixChars(word_in, word_out);

                while (j < strlen(word_in))
                    outstr[i++] = word_out[j++];
            }
        }
        else
            outstr[i] = instr[i];

        i++;
    }

    if (i == strlen(instr) && flag == IN_WORD)
    {
        word_in[j] = '\0';
        i -= strlen(word_in);
        j = 0;

        if (word_status(word_in) == WORD_CANNOT_BE_CHANGED)
        {
            while (j < strlen(word_in))
                outstr[i++] = word_in[j++];
        }
        else
        {
            clean_buf(word_out, SYMBOLS_IN_LINE);
            mixChars(word_in, word_out);

            while (j < strlen(word_in))
                outstr[i++] = word_out[j++];
        }
    }

    return outstr;
}