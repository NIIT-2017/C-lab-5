#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include "task3.h"
#include <time.h>
#include <stdlib.h>
#define sLMax 256 // max length of string

FILE *mf1;
FILE *mf2;

int main()
{	
	char in[sLMax] = {0};
	char out[sLMax];
	srand(time(0));
	
	mf1 = fopen("task3.txt", "r");
	if (mf1 == NULL)  // Проверка открытия файла
	{
		printf("file open error\n");
		return -1;
	}
	mf2 = fopen("task3-2.txt", "w");
	if (mf2 == NULL)  // Проверка открытия файла
	{
		printf("file open error\n");
		return -2;
	}
	
	while ( fgets(in, sLMax, mf1) != NULL)
		fputs(mixLine(in, out), mf2);
		
	fclose(mf1);
	fclose(mf2);
	return 0;
}