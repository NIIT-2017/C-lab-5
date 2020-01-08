#include <string.h>
#include <stdlib.h>

#define SIZE 1024

char* randomWords(char* in, char* out)
{
	int true1 = 1;
	while (true1)
	{
		char* p[SIZE] = { 0 };
		int i = 0, numb = 0, count = 0, inword = 0, random = 0;
		int a = 0;
		while (in[i])
		{
			if (in[i] != ' ' && inword == 0)
			{
				p[numb] = &in[i];
				inword = 1;
				count++;
				numb++;
			}
			else if (in[i] == ' ' && inword == 1)
			{
				inword = 0;
			}
			i++;
		}
		if (count > 1)
		{
			for (int k = count; k > 1; k--) // Тассование Фишера Йетса методом Дуршенфельда
			{
				random = rand() % k;
				char* m = p[k - 1];
				p[k - 1] = p[random];
				p[random] = m;
			}

			for (int i = 0; i < count; i++)
			{
				do
				{
					out[a] = *p[i];
					a++;
					p[i]++;
				} while (*(p[i]) != ' ' && *(p[i]) != '\0');
				if (i != count - 1)
				{
					out[a] = ' ';
					a++;
				}
				else if (i == count - 1)
					out[a] = '\0';
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