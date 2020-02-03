#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"task1.h"

#define LINE 250

int main(void)
{
	FILE*fp;
	char in[LINE][SIZE]; //from file to there
	char out[LINE][SIZE]; //from there to file

	if ((fp = fopen("task4.txt", "a+")) == NULL) //readding and writing
	{
		puts("File open ERROR!");
		return 1;
	}

	int i = 0; //for account entered lines for not to go beyond the bounds of  array "in"
	while (i < LINE && fgets(in[i], SIZE, fp) != NULL)
	{
		if (in[i][strlen(in[i]) - 1] == '\n')
			in[i][strlen(in[i]) - 1] = '\0';

		randomWords(in[i], out[i]); //  addresses of entered lines
		i++;
	}
	in[i][strlen(in[i])] = '\0'; //for the last line, becouse there can to de EOF, not '\n'

	for (int z = 0; z < i; z++)
		fprintf(fp, "\n%s", out[z]);

	if (fclose(fp) != 0)
		puts("Error closing the file!");
	return 0;
}