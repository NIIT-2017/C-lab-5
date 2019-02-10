#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 128

char * randomWords(char * in, char *out)
{
    char *token[N];
    int i = 0, j = 0, count = 0;
    int state = 0;                                  // 0 - вне токена, 1 - внутри токена

    if(in[strlen(in) - 1] == '\n')                  // стандартная зачистка
        in[strlen(in) - 1] = 0;

    for (i = 0; in[i]; i++)                         // идём по исходной строке и выделяем токены, маркер - пробел
    {
        if (in[i] !=' ' && state == 0)              //
        {
            token[count] = &in[i];                  // сохраняем в массив токенов адреса элементов из in
            state = 1;                              // меняем статус на "внутри токена"
            count++;                                // увеличиваем счётчик токенов
        }
        else if(in[i] == ' ' && state == 1)         // если дошли до пробела, меняем статус "внутри токена" на "вне токена"
            state = 0;
    }

    srand(time(0));
    for(i = 0; i < count; i++)                     // вносим элемент хаоса
    {
        int a = rand()%count;
        char *temp = token[i];
        token[i] = token[a];
        token[a] = temp;
    }

    for(i = count - 1; i >= 0; i--)                 // заполняем массив out токенами в случайном порядке
    {
        while (*token[i]!=' ' && *token[i]!='\0')   // пока указатель на i-й элемент массива указателей не является пробелом и \0
        {
            out[j++] = *token[i];                   // сохраняем в массив out указатели на токены
            token[i]++;
        }
        out[j++] = ' ';                             // добавляем в массив out пробелы между токенами
    }

    out[strlen(in)] = '\0';                         // добавляем \0 в конец получившейся строки
    return out;
}
