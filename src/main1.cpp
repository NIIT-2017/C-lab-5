#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "task1.h"


#define N 256

int main()
{
	char buf[N];
	char str[N];
	srand((unsigned int)time(0));
	printf("Enter the string:\n");
	fgets(buf, N, stdin);

	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';

	printf("%s", randomWords(buf, str));
	return 0;
}