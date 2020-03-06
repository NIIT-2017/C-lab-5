#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "task1.h"

int main()
{
	FILE* fp = fopen("111.txt", "r"),
		* up = fopen("222.txt", "w");
	if (fp == NULL)
		printf("\nFile opening error\n");
	else
	{
		char StringIN[256] = { 0 };
		char StringOut[256] = { 0 };

		int end = 0;

		while (!end)
		{
			if (fgets(StringIN, 256, fp))
			{
				if (*StringIN != 0 && StringIN[strlen(StringIN) - 1] == '\n')
					StringIN[strlen(StringIN) - 1] = '\0';
				fprintf(up, "%s\n", randomWords(StringIN, StringOut));
			}
			else
				break;
			end = feof(fp);
		}
	}
	return 0;
}