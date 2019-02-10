#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * randomWords(char * in, char *out)
{
	int i = 0;
	int j = 1;
	int k = 0;
	int count = 0;
	char *p[10];
	char *slovo;
	char del[10] = " \n";
	slovo = strtok(&in[i], del);
	p[0] = slovo;
	while (slovo != NULL)
	{
		slovo = strtok(NULL, " \n");
		p[j] = slovo;
		j++;
		count++;
	}
	while (k < count)
	{
		int m = 0;
		m = rand() % count;
		strcat(out , p[m]);
		strcat(out, " ");				
		count--;
	}
	puts(out);
	return out;
}