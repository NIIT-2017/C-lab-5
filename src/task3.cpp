#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"task3.h"

char* mixLine(char* instr, char* outstr)
{
	char* in[SIZE];
	char* out[SIZE];
	int flag = 0;
	int i;

	for (i = 0; *(instr + i) != '\0'; i++)
	{
		if (*(instr + i) != ' ' && flag == 0)
		{
			flag = 1;
			in[i] = (instr + i);
			out[i] = (outstr + i);
			mixChars(in[i], out[i]);
		}

		else if (*(instr + i) == ' ' && flag == 1)
		{
			flag = 0;
			outstr[i] = ' ';
		}
	}
	outstr[i] = '\0';  //for defebce of trash

	return outstr;
}

char* mixChars(char* in, char* out)
{
	char* p_in[SIZE];
	char* p_out[SIZE];
	srand(time(NULL));
	int Min = 0, Max; //start and end of a word
	int index_rand;

	for (int k = 0; k < SIZE; k++)
	{
		p_in[k] = in + k;

		if (*(in + k) == ' ' || *(in + k) == '\0')
		{
			Max = k - 1; //index end of a word
			break;
		}
	}

	p_out[Min] = p_in[Min]; //the first letter of a word is const
	for (int j = (Min + 1); j < Max; j++)
	{
		index_rand = (Min + 1) + rand() % ((Max - 1) - (Min + 1) + 1); //  Min < index_rand < Max
		for (int z = (Min + 1); z <= j; z++)
		{
			if (j == (Min + 1))
				p_out[j] = p_in[index_rand];

			else if (p_out[z] == p_in[index_rand])  //verification of used addresses for replace index_rand
			{
				index_rand = (Min + 1) + rand() % ((Max - 1) - (Min + 1) + 1);
				z = 0;
			}
			else if (z == j  &&  j != (Min + 1))
				p_out[j] = p_in[index_rand];
		}
	}
	p_out[Max] = p_in[Max]; //the last letter of a word is const

	for (int i = 0; i <= Max; i++)
		out[i] = *p_out[i];
	out[Max + 1] = '\0'; //for defebce of trash

	return out;
}