#include <stdio.h>
#include <string.h>
#include "task1.h"
int main()
{
	char in[256];
	char out[256];
	FILE* rf;
	FILE* wf;
	int eof = 0;
	rf = fopen("C:\\labsss\\dano.txt", "r");
	wf = fopen("C:\\labsss\\polucheno.txt", "w");
	while (!eof)
	{
		if (fgets(in, 256, rf))
		{
			if (*in != 0 && in[strlen(in) - 1] == '\n')
				in[strlen(in) - 1] = '\0';
			fputs(randomWords(in, out), wf);
			fputs("\n", wf);
		}
		else
			break;
		eof = feof(rf);
	}
	return 0;
}