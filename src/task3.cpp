#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define N 1024

char* mixChars(char* in, char* out)
{
	int count = 0, j = 0, random = 0,a = 1,true1 = 1;
	char* p[N] = { 0 };
	for (int i = 0; in[i] != ' '&& in[i] != '\0'; i++)
	{
		if (i == 0)
		{
			out[i] = in[i];
		}
		else if (in[i + 1] == ' '|| in[i + 1] == '\0')
		{
			out[i] = in[i];
		}
		else
		{
			out[i] = in[i];
			p[j] = &in[i];
			j++;
			count++;
		}
	}
	if (count > 1)
	{
		while (true1)
		{
			a = 1;
			for (int k = count; k > 1; k--) // Тассование Фишера Йетса методом Дуршенфельда
			{
				random = rand() % k;
				char* m = p[k - 1];
				p[k - 1] = p[random];
				p[random] = m;
			}
			for (int i = 0; i < count; i++)
			{
				out[a] = *p[i];
				a++;
			}
			for (int i = 0; i < strlen(out); i++)// Проверка получившейся строки (должна отличаться от исходной)
			{
				if (out[i] == in[i])
					continue;
				else
				{
					true1 = 0;
					break;
				}
			}
		}
	}
	return out;
}
char* mixLine(char* instr, char* outstr)
{
	int i = 0, inword = 0;
	while (instr[i])
	{
		if (instr[i] != ' ' && inword == 0)
		{
			mixChars(&instr[i], &outstr[i]);
			inword = 1;
		}
		else if (instr[i] == ' ' && inword == 1)
		{
			outstr[i] = instr[i];
			inword = 0;
		}
		i++;
	}
	if (inword == 1)
	{
		outstr[i] = '\0';
	}
	return outstr;
}
