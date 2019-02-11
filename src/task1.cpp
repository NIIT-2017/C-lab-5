#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * randomWords(char * in, char *out) {
    if(in[strlen(in) - 1] == '\n')
        in[strlen(in) - 1] = '\0';
    char *words[20];
    int count = 0; // количество слов
    int i = 0;
    int inWord = 0; // флаг в слове = 1
    
    while (in[i] != '\0') {
        if (inWord == 0 && in[i] != ' ') {
            inWord = 1;
            words[count] = &in[i];
            count++;
        }
        if (in[i] == ' ') {
            inWord = 0;
        }
        i++;
    }
    
    int j = 0;
    
    while (count != 0) {
        i = rand() % count;
        char *p = words[i];
        while (*p != '\0' && *p != ' '){
            out[j] = *p++;
            j++;
        }
        out[j++] = ' ';
        char* t = words[i]; // указатель на слово
        words[i] = words[count - 1];
        words[count - 1] = t;
        count--;
    }
    
    out[strlen(out)-1] = '\0';
    
    return out;
}
    
