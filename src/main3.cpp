#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

#define N 20
#define M 256

int main() {

	char arr[N][M] = { '\0' }; 
	char outstr[M] = { '\0' };

	FILE * fp = NULL;
	fp = fopen("text.txt", "r+");

	if (fp == NULL) {
		printf("Your file can not be find\n");
		return 1;
	}

	FILE * fpW = NULL;
	fpW = fopen("myfile.txt", "w");

	if (fpW == NULL) {
		printf("Your file can not be find\n");
		return 1;
	}

	int strNumber = 0;
	while (!feof(fp)) {
		fgets(arr[strNumber], M, fp);
		mixLine(arr[strNumber], outstr); 
		fprintf(fpW, "%s\n", outstr);
		strNumber++;
	}

	fclose(fp);
	fclose(fpW);

	return 0;
}