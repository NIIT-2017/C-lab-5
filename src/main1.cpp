/*Ќаписать программу, котора€ принимает от пользовател€ строку и
выводит ее на экран, перемешав слова в случайном пор€дке.*/
#include <stdio.h>
#include "task1.h"
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(0));
	char in[256] = { '\0' };
	char out[256] = { '\0' };
	printf("Enter the string: ");
	fgets(in, 256, stdin);
	printf("%s\n", randomWords(in, out));

	return 0;
}