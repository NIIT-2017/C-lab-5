/* Ќаписать программу, котора€ принимает от пользовател€ строку и
выводит ее на экран, перемешав слова в случайном пор€дке.*/

#include <stdio.h>
#include "task1.h"


int main()
{
	char in[256] = { 0 };
	char out[256] = { 0 };
	fgets(in, 256, stdin);
	randomWords(in, out);
	return 0;
}