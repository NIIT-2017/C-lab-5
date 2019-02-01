#include "task1.h"
#define SIZE 256
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	char strIn[SIZE] = { 0 }, strOut[SIZE] = { 0 };
	printf("Just write some words: ");
	gets(strIn);
	puts(randomWords(strIn, strOut));
	return 0;
}