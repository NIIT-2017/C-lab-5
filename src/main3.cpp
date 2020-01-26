#include "task3.h"
#include <time.h>
#include <string.h>

int main()
{
    time_t now;
    time(&now);
    srand(now);

    FILE *fp_in, *fp_out;

    fp_in = fopen("lines_in.txt", "rt");
    fp_out = fopen("lines_out.txt", "wt");

    if (!fp_in)
    {
        puts("Error: file is not found");
        return 1;
    }

    int ch;
    int count_of_lines = 0;
    while ((ch = fgetc(fp_in)) != EOF)
        if (ch == '\n')
            count_of_lines++;

    rewind(fp_in);

    char lines_in[LINES][SYMBOLS_IN_LINE] = { 0 };
    char lines_out[LINES][SYMBOLS_IN_LINE] = { 0 };

    for (int i = 0; i < count_of_lines; i++)
    {
        fgets(lines_in[i], SYMBOLS_IN_LINE, fp_in);
        mixLine(lines_in[i], lines_out[i]);
        fprintf(fp_out, "%s\n", lines_out[i]);
    }

    fclose(fp_in);
    fclose(fp_out);
    printf("File lines_out.txt has been added\n");

    /*
    char buf[100] = "hello world";
    char buf2[100] = { 0 };

    mixLine(buf, buf2);
    printf("%s", buf2);
    */

    return 0;
}