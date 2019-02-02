#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "task1.h"
#define N 100



int main()
{
	
	char in[N], out[N];
	fgets(in, N, stdin);
	randomWords(in, out);
	puts(out);
	return 0;
	
}

