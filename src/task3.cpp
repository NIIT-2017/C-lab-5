#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char *mixChars(char *in, char *out)
{
	char temp;
	strcpy(out, in);
	for (int i = 1; i < strlen(out) - 1;i++)
	{
		int j = rand() % (strlen(out) - 2) + 1;
		temp = out[i];
		out[i] = out[j];
		out[j] = temp;
	}
	return out;
}
char *mixLine(char *instr, char * outstr)
{
	int i = 0;
	int j = 0;
	char in[256];
	char inst[256];
	strcpy(in, instr);;
	char out[256] = { 0 };
	char *word[10];
	char del[10] = " \n";
	
	word[0] = strtok(in, del);
	while (1)
	{
		
		
		
		if (word[j] == NULL)
		{
			break;
		}
		strcpy(inst, word[j]);
		mixChars(inst, out);
		strcat(outstr, out);
		strcat(outstr, " ");
		j++;
		word[j] = strtok(NULL, del);
		
	}
	printf("%s", outstr);
	return outstr;
}
