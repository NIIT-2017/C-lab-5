#include <stdio.h>
#include "task1.h"


int main(void)
{
	char in[256];
	char out[256];

	fgets(in, 256, stdin);
	randomWords(in, out);
	printf("%s", out);

	getchar();
	return 0;
}