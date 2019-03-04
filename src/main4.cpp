#include <stdio.h>
#include <string.h>
#include "task1.h"

int main() {

	char in[30][256] = { '\0' };
	char out[256] = { '\0' };

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
		fgets(in[strNumber], 256, fp);
		randomWords(in[strNumber], out);
		fprintf(fpW, "%s\n", out);
		for (int i = 0; i < strlen(out); i++)
			out[i] = '\0';
		strNumber++;
	}
	fclose(fp);
	fclose(fpW);
	return 0;
}