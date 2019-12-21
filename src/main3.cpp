#define _CRT_SECURE_NO_WARNINGS

#include "task3.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char instr[256];
    char outstr[256];
    long int beginOfStr = 0;
    int eof = 0;
    
    FILE* fp;

    /*fp = fopen("C:\\Labs\\Item.txt", "w");

    fputs("blackflag bowl   crush\nexist   \n   computer hp", fp);

    fclose(fp);*/

    /*fp = fopen("C:\\Labs\\Item.txt", "r+");

    while (fgets(instr, 256, fp))
    {
        eof = feof(fp);
        fseek(fp, beginOfStr, SEEK_SET);
        fputs(mixLine(instr, outstr), fp);
        beginOfStr = ftell(fp);
    }

    fclose(fp);*/

    while (!eof)
    {
        fp = fopen("C:\\Labs\\Item.txt", "r+");
        fseek(fp, beginOfStr, SEEK_SET);
        if (!(fgets(instr, 256, fp)))
            break;
        eof = feof(fp);
        fclose(fp);

        fp = fopen("C:\\Labs\\Item.txt", "r+");
        fseek(fp, beginOfStr, SEEK_SET);
        fputs(mixLine(instr, outstr), fp);
        beginOfStr = ftell(fp);
        fclose(fp);
    }

    return 0;
}