#include<string.h>
#include<time.h>
#include<stdlib.h>
#define N 100

void shakeArr(char *arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int k = rand() % size;
		char *t = arr[i];
		arr[i] = arr[k];
		arr[k] = t;
	}
}

char * randomWords(char * in, char *out)
{
	int i = 0, j = 0;
	char *arr[N] = { 0 };
	clock_t start, finish;
	srand(time(0));

	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';

	if (in[0] > 0)
		arr[j] = &in[0];
	else
		j = -1;

	for (i = 0; in[i] != '\0'; i++)
	{
		if ((in[i] == ' ') && (in[i + 1] > 0))
			arr[++j] = &in[i + 1];
	}
	int size = j;
	start = clock();
	shakeArr(arr, size);
	finish = clock();
	i = 0;
	for (j=0; j <= size; j++)
	{
		while (*arr[j] != ' ' && *arr[j] != '\0')
			out[i++] = *arr[j]++;
		out[i++] = ' ';
	}
	out[--i] = '\0';
	return out;
}