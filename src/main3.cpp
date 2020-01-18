#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "task3.h"

#define SIZE 50

int main() {
    int i = 0;
    char instr[SIZE][256];
    char outstr[SIZE][256];

    FILE *fp = fopen("toRead.txt", "rt");
    if (!fp) {
        printf("Error!\n");
        return 1;
    }

    FILE *fp1 = fopen("toWrite.txt", "w");
    if (!fp1) {
        printf("Error!");
        return 1;
    }

    while (fgets(instr[i], 256, fp)) {
        if (instr[i][strlen(instr[i]) - 1] == '\n') {
            instr[i][strlen(instr[i]) - 1] = 0;
        }
        printf("%s \n", mixLine(instr[i], outstr[i]));
        fprintf(fp1, "%s\n", outstr[i]);
        i++;
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}