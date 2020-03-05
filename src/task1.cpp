#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char* randomWords(char* in, char* out)
{
	int inWord = 0, //ôëàã íàõîæäåíèÿ â ñëîâå
		count = 0, //ñ÷åò÷èê êîëè÷åñòâà ñëîâ
		i = 0;
	char* buf[64];

	for (; i < 256 && in[i]; i++) 
	{
		if (in[i] == ' ')
			inWord = 0;
		else if (in[i] != ' ' && inWord == 0)
		{
			inWord = 1;
			buf[count++] = &in[i];
		}
	}
	buf[count] = &in[i]; 
	
	if (*in != 0) // 
	{
		int l = 0,
			p = 0,
			max = count;
		char* bubble = NULL;
		srand(time(NULL));
		for (; max > 0; max--)
		{
			p = rand() % max;
			for (int k = 0; *(buf[p] + k) != '\0' && *(buf[p] + k) != ' '; k++, l++)
				out[l] = *(buf[p] + k);
			out[l] = ' ';
			l++;
			while (*buf[p] != '\0')
			{
				buf[p] = buf[p + 1];
				p++;
			}
		}
		if (out[l - 1] == ' ')
			out[l - 1] = '\0';
		else
			out[l] = '\0';
	}
	else
		out[0] = 0;

	return out;
}