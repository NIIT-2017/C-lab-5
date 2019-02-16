#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task1.h"
#define N 256

int main()
{
	char in[N]; // исходная строка
	char out[N]; // строка in c обратным порядком слов
	srand(time(NULL));
	printf("Enter your string: ");
	fgets(in, N, stdin);
	randomWords(in, out);
	printf("%s", out);
	return 0;
}