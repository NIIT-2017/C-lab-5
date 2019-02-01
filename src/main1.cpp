#include "task1.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char in[260], out[260];
	char input[256];
	fgets(in, 256, stdin);
	puts(randomWords(in, out));
	return 0;
}


