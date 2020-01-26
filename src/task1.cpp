#include "task1.h"
#define IN_WORD 1
#define OUT_WORD 0
#define IN_AND_OUT_ARE_IDENTICAL 1
#define IN_AND_OUT_ARE_NOT_IDENTICAL 0

void generate_arr_of_points(char* in, char** points, int* count)
{
    int i = 0;
    int j = 0;
    int flag = OUT_WORD;

    while (in[i])
    {
        if (flag == OUT_WORD && in[i] != ' ')
        {
            flag = IN_WORD;
            points[j] = &in[i];
            j++;
        }
        else if (flag == IN_WORD && in[i] == ' ')
        {
            flag = OUT_WORD;
            (*count)++;
        }
        i++;
    }
    if (flag == IN_WORD && in[i] == '\0')
        (*count)++;
}

void generate_out(char** points, int count,char* in, char* out, int i, int flag)
{
    int r = 0;
    char* p;
    char* change;

    if (count > 0)
    {
        r = rand() % count + 0;
        p = points[r];

        if (*p == in[i] && flag == IN_AND_OUT_ARE_IDENTICAL)
            flag = IN_AND_OUT_ARE_IDENTICAL;
        else
            flag = IN_AND_OUT_ARE_NOT_IDENTICAL;

        while (1)
        {
            out[i] = *p;

            if (out[i] == '\0')
                out[i] = ' ';

            i++;
            p++;

            if (out[i - 1] == ' ')
                break;
        }

        change = points[count - 1];
        points[count - 1] = points[r];
        points[r] = change;

        count--;

        generate_out(points, count, in, out, i, flag);
    }
    else
    {
        out[i - 1] = '\0';

        if (flag == IN_AND_OUT_ARE_IDENTICAL)
        {
            generate_arr_of_points(in, points, &count);
            generate_out(points, count, in, out, 0, IN_AND_OUT_ARE_IDENTICAL);
        }
    }
}

char* randomWords(char* in, char* out)
{
    int count_of_words=0;
    int r = 0;
    char* points[SIZE_OF_LINE] = { 0 };

    time_t now;
    time(&now);
    srand(now);

    generate_arr_of_points(in, points, &count_of_words);
    generate_out(points, count_of_words, in, out, 0, IN_AND_OUT_ARE_IDENTICAL);
    return out;
}