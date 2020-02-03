#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include"task1.h"

char* randomWords(char *in, char *out)
{
	char* p1[SIZE / 2] = { 0 };
	char* p_rand[SIZE / 2] = { 0 };  //for random address
	int words = 0; //count of words
	int flag = 0;//if simbol==' '; flag==1 if simbol!=' '
	int index_rand;
	srand(time(NULL));

	for (int i = 0; i < strlen(in); i++)
	{
		if (in[i] != ' ' && flag == 0)
		{
			flag = 1;
			p1[words] = &in[i]; //remember the address of hte beginning of the word
			words++;   //this is an address of the last word
		}
		else if (in[i] != ' ' && flag == 1)
			;

		else if (in[i] == ' ' && flag == 1)
			flag = 0;
	}
	
	for (int j = 0; j < words; j++)
	{
		index_rand = 0 + rand() % ((words - 1) - 0 + 1);
		for (int z = 0; z <= j; z++)
			{
				if (j == 0)
					p_rand[z] = p1[index_rand];

				else if (p_rand[z] == p1[index_rand])
				{
					index_rand = 0 + rand() % ((words - 1) - 0 + 1);
					z = -1; //becouse in for( ; ; z++) we'll get z=0 and check will begin z=0
				}

				else if (z == j && j != 0)  //only if we didn't use the index_rand
					p_rand[z] = p1[index_rand];
			}
		}

		int j, k;
		for (j = 0, k = 0; k < words, j < strlen(in); j++)
		{
			if (*p_rand[k] != ' ' && *p_rand[k] != '\0')
			{
				out[j] = *p_rand[k];
				*(p_rand[k]++);
			}

			else if (*p_rand[k] == '\0')
			{
				out[j] = ' ';
				k++; //go to an adress of the next word
			}

			else if (*p_rand[k] == ' ')
			{
				out[j] = ' ';
				k++;
			}
		}
		out[j] = '\0';

		return out;
	}
	