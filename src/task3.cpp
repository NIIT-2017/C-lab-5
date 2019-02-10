#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define N 128

char *mixChars(char *in, char *out) // перемешивание символов в одном слове
{
    int i = 0, count = 0;
    while (isalpha(in[i]))
    {
        out[i] = in[i];
        count++;
        i++;
    }

        if(count >= 4)
        {
            for(i = 1; i < (count - 2); i++)
            {
                int j = rand()%(count - 2)+1;
                if(j != i)
                {
                    char temp = out[i];
                    out[i] = out[j];
                    out[j] = temp;
                }
            }
        }
    return out;
}

char *mixLine(char *instr, char * outstr) // перемешивание для целой строки
{

    int i = 0;
    int state = 0;                                     // 0 - вне токена, 1 - внутри токена

    if(instr[strlen(instr) - 1] == '\n')               // стандартная зачистка
            instr[strlen(instr) - 1] = 0;

    for (i = 0; instr[i]; i++)                         // идём по исходной строке и выделяем токены, маркер - пробел
    {
        if (instr[i] !=' ' && state == 0)
        {
            mixChars(&instr[i], &outstr[i]);           // перемешиваем буквы
            state = 1;                                 // меняем статус на "внутри токена"
        }
        else if(instr[i] == ' ' && state == 1)
        {
            outstr[i] = instr[i];
            state = 0;                                 // если дошли до пробела, меняем статус "внутри токена" на "вне токена"
        }
    }
    outstr[i] = '\0';                      // добавляем \0 в конец получившейся строки
    return outstr;
}
