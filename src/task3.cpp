#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define N 128

char *mixChars(char *in, char *out) // перемешивание символов в одном слове
{
    srand(time(0));

    for (int i = 0; isalpha(in[i]); i++)
    {
        out[i] = in[i];
        if(strlen(in) >= 4)
        {
            for(int i = 1; i < (strlen(in) - 2); i++)
            {
                int j = rand()%(strlen(in) - 2);
                if(j != i)
                {
                    char temp = out[i];
                    out[i] = out[j];
                    out[j] = temp;
                }
            }
        }
    }
    return out;
}

char *mixLine(char *instr, char * outstr) // перемешивание для целой строки
{

    int i = 0;
    int state = 0;                                     // 0 - вне токена, 1 - внутри токена
    char in[64] = {0}, out[64] = {0};

    if(instr[strlen(instr) - 1] == '\n')                  // стандартная зачистка
            instr[strlen(instr) - 1] = 0;

    for (i = 0; instr[i]; i++)                         // идём по исходной строке и выделяем токены, маркер - пробел
    {
        if (instr[i] !=' ' && state == 0)
        {
            mixChars(in, out);                         // перемешиваем буквы
            state = 1;                                 // меняем статус на "внутри токена"
        }
        else if(instr[i] == ' ' && state == 1)
            outstr[i] = instr[i];
            state = 0;                                 // если дошли до пробела, меняем статус "внутри токена" на "вне токена"
    }
    outstr[strlen(instr)] = '\0';                      // добавляем \0 в конец получившейся строки
    return outstr;
}
