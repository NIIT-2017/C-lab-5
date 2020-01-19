#include <stdlib.h>
#include <string.h>
#include <time.h>


char *arr[128];

char *mixChars(char *in, char *out) {
    char swap;
    char *endOfWord = in;
    char *originalIn = in;
    char *originalOut = out;
    while (*endOfWord != ' ' && *endOfWord != '\0') {  //You looking for last symbol of words
        endOfWord++;
    }
    endOfWord--;                                  // Going back to last symbol

    in++;                                        // Ignoring first and last symbols
    endOfWord--;

        time_t now;
        time(&now);
        srand(now);
        int randomNumber = 0;
        while (in < endOfWord) {                                //While beginning and end to meet each over
            randomNumber = rand() % (endOfWord - in + 1);          //You get a random element number of symbol in word
            swap = *endOfWord;                                 //You change places of words in the string
            *endOfWord = *(in + randomNumber);
            *(in + randomNumber) = swap;
            endOfWord--;
        }
    while (*originalIn) {                          //Copying mixed word to out
        *out = *originalIn;
        out++;
        originalIn++;
    }
    *out = '\0';
    return originalOut;
}

char *mixLine(char *instr, char *outstr) {
    int i = 0;
    int count = 0;
    int countOfWords = 0;
    char *pWord;
    int inWord = 0;
    char *firstElement = outstr;
    char changedWord[256];
    while (*instr) {
        if (*instr != ' ' && inWord == 0) {     //Reading a string up to the end and looking for words in string
            count++;
            arr[i] = instr;                    //Writing down an adress of first symbol of word in array of pointers
            i++;
            inWord = 1;
        } else if (*instr == ' ' && inWord == 1) {
            inWord = 0;
        }
        instr++;                                    //Moving to next element in  array of pointers
    }
    countOfWords = count;

   for (int i = 0; i < countOfWords; i++) {
       pWord = mixChars(arr[i], changedWord);      //Writing down the result of function work in variable, wich is a pointer of first symbol on mixed word
       while (*pWord != ' ' && *pWord != '\0') {
           *outstr = *pWord;
           outstr++;                                //Copying a word in string symbol by symbol
           pWord++;
       }
       *outstr = ' ';                              //When the word finishes to put down a space and move to next pointer
       outstr++;
   }
    outstr--;
    *outstr = '\0';

    return firstElement;
}