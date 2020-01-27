#include<stdio.h>
#include<string.h>
#include"task1.h"

int main(void)
{
	char in[SIZE];
	char out[SIZE];

	puts("Enter a line:");
	fgets(in, SIZE, stdin);
	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';

	randomWords(in, out);
	puts("Random of our line:");
	for (int z = 0; z < strlen(in); z++)
		printf("%c", out[z]);
	printf("\n");

	return 0;
}