#include "task3.h"

#define size 256

int letter(char a) {
    if (a == ' ' || a == '\n' || a == '\0')
        return 0;
    else
        return 1;
}

char* mixChars(char* in, char* out) {
    int i = 0, count = 0;
    while (letter(in[i]) == 1) {
        out[i] = in[i];
        count++;
        i++;
    }
    srand(time(NULL));
    if (count > 3) {
        for (i = 1; i <= count - 2; i++) {
            int k = 1 + rand() % (count - 2) - 1 + 1;
            while (k == i) {
                k = 1 + rand() % (count - 2) - 1 + 1;
            }
            char tmp = out[i];
            out[i] = out[k];
            out[k] = tmp;
        }
    }
    return out;
}

char* mixLine(char* instr, char* outstr) {
    int InWord = 0;
    int i = 0, count = 0;
    while (instr[i]) {
        if (letter(instr[i]) == 1 && InWord == 0) {
            mixChars(&instr[i], &outstr[i]);
            InWord = 1;

            i++;
        }
        else if (letter(instr[i]) == 1 && InWord == 1) {
            i++;
        }
        else if (letter(instr[i]) == 0 && InWord == 1) {
            outstr[i] = instr[i];
            InWord = 0;
            i++;
        }
    }
    return outstr;
}