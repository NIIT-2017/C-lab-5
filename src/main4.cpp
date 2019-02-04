#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "task1.h"

#define N 10
#define M 256

int main()
{
	char buf[N][M] = {0};
	char str[N][M] = {0};
	srand((unsigned int)time(0));

	int count = 0;
	FILE *fp1, *fp2;
	fp1 = fopen("11.txt", "r");
	fp2 = fopen("22.txt", "w+" );
	if (fp1 == NULL)
	{
		puts("File not found!");
		return 1;
	}
	while (count < N && *fgets(buf[count], M, fp1) != '\n')
	{
		randomWords(buf[count], str[count]);
		fputs(str[count], fp2);
		putc('\n', fp2);
		count++;
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}