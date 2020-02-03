#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

char *randomWords(char *in, char *out) {
    char *arr[128];
    int i = 0;
    int j = 0;
    int count = 0;
    int countOfWords = 0;
    char *pWord;
    int inWord = 0;
    char *swap;
    char *firstElment = out;

    while (*in) {
        if (*in != ' ' && inWord == 0) {     //You read a string up to the end and looking for words in string
            count++;
            arr[i] = in;                    //You write down an adress of first word`s symbol of word in array of pointers
            i++;
            inWord = 1;
        } else if (*in == ' ' && inWord == 1) {
            inWord = 0;
        }
        in++;                                    //You move to next element in  array of pointers
    }
    countOfWords = count;

    time_t now;
    time(&now);
    srand(now);
    int randomNumber = 0;
    while (count > 1) {
        randomNumber = rand() % count;          //You get a random element number of word in a string
        swap = arr[count - 1];                    //You change places of words in the string
        arr[count - 1] = arr[randomNumber];
        arr[randomNumber] = swap;
        count--;
    }

    for (j = 0; j < countOfWords; j++) {                //You read a new string
        pWord = arr[j];
        while (*pWord != ' ' && *pWord != '\0') {
            *out = *pWord;                           //A pointer gets an adress of first symbol of word
            pWord++;                                //You move to next symbol
            out++;
        }
        *out = ' ';
        out++;
    }
    out--;
    *out = 0;
    return firstElment;
}

