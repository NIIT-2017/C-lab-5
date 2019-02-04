#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"

#define M 256
#define N 10

int main()
{
	char str[N][M] = {0};
	char buf[N][M] = {0};
	int count = 0;
	srand((unsigned int)time(0));
	FILE *fp1, *fp2;
	fp1 = fopen("10.txt", "r");
	fp2 = fopen("20.txt", "w+");
	if (fp1 == NULL)
	{
		puts("File not found!");
		return 1;
	}
	while (count < N && *fgets(str[count], M, fp1) != '\n')
	{
		mixLine(str[count], buf[count]);
		fputs(buf[count], fp2);
		putc('\n', fp2);
		count++;
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}