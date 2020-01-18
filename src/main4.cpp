#include <string.h>
#include <stdio.h>
#include "task1.h"

int main() {
    char in[128];
    char out[128];

    FILE *fp = fopen("toRead4.txt", "rt");
    if (!fp) {
        printf("Error!\n");
        return 0;
    }

    while (fgets(in, 128, fp)) {
        if (in[strlen(in) - 1] == '\n') {
            in[strlen(in) - 1] = 0;
        }
        randomWords(in, out);
    }

    FILE *fp1 = fopen("toWrite4.txt", "w");
    if (!fp1) {
        printf("Error!");
    }
    randomWords(in, out);
    for (int i = 0; i<1; i++) {
        fprintf(fp1, "%s\n", out);
    }
    fclose(fp);
    fclose(fp1);

    return 0;
}