#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../task1/task1.h"
#include "task4.h"
#define SIZE 256

int main()
{
	char in[SIZE] = { 0 };
	char out[SIZE] = { 0 };
	
	FILE * fp;
	fp = fopen("wind.txt", "rt");
	if (!fp)
	{
		puts("File error!");
		return 1;
	}
	while (fgets(in, SIZE, fp))
	{
		printf("Prepared string: %s", randomWords(in, out));	
	}
   
	fclose(fp);

	return 0;
}