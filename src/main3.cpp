#include <stdio.h>
#include <string.h>
#include "task3.h"
#define STRING 16
#define SYMBOLS 256

int main()
{
	FILE* fp = fopen("text.txt", "r"),
		* up = fopen("inverted_text.txt", "w");
	if (fp == NULL)
		printf("\nFile opening error\n");
	else
	{
		char ArrayOfString[256] = { 0 };
		char SecondArray[256] = { 0 };
		int end = 0;

		while (!end)
		{
			if (fgets(ArrayOfString, 256, fp))
			{
				if (*ArrayOfString != 0 && ArrayOfString[strlen(ArrayOfString) - 1] == '\n')
					ArrayOfString[strlen(ArrayOfString) - 1] = '\0';
				fprintf(up, "%s\n", mixLine(ArrayOfString, SecondArray));
			}
			else
				break;
			end = feof(fp);
		}
	}
	return 0;
}