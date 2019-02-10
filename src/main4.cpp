#include <stdio.h>
#include "task1.h"
int main()
{
	char in[256] = { 0 };
	char out[256] = { 0 };
	FILE *fp;
	fp = fopen("1.txt", "r");
	if (fp == NULL)
	{
		puts("Fail ne nayden");
		return 1;
	}

	fgets(in, 256, fp);
	randomWords(in, out);
}