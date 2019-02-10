#include "task3.h"
#include <stdio.h>

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
	printf("%s", out);
	mixLine(in, out);

	return 0;
}