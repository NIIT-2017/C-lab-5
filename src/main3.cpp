#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "task3.h"
#define STRING 10
#define SYMBOLS 256

int main()
{
	FILE* fp = fopen("111.txt", "r"),
		* up = fopen("222.txt", "w");
	if (fp == NULL)
		printf("\nFile opening error\n");
	else
	{
		char String[256] = { 0 };
		char m[256] = { 0 };
		int end = 0;

		while (!end)
		{
			if (fgets(String, 256, fp))
			{
				if (*String != 0 && String[strlen(String) - 1] == '\n')
					String[strlen(String) - 1] = '\0';
				fprintf(up, "%s\n", mixLine(String, m));
			}
			else
				break;
			end = feof(fp);
		}
	}
	return 0;
}