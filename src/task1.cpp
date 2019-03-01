
#include <string.h>
#include <cstring>
#include <time.h> 
#include <cstdlib>


char * randomWords(char * in, char *out)
{
	int j = 0, i = 0, k = 0, counter = 0, r = 0;
	char arr[100][100];
	while (in[j] != '\0')
	{
		while (in[j] != ' ' & in[j] != '\0')
		{
			arr[i][k] = in[j];
			j++;
			k++;
		}
		arr[i][k] = '\0';
		k = 0;
		i++;
		if (in[j]!='\0')
		j++;
		counter++;
	}
	j = 0; i = 0;
	k = counter;
	while (counter != 0)
	{
		srand(time(NULL));
		i = rand() % k;
		if (arr[i][0] != 0)
		{
			while (arr[i][j] != '\0')
			{
				out[r] = arr[i][j];
				r++;
				j++;
			}
			out[r] = ' ';
			j = 0;
			r++;
			counter--;
			arr[i][0] = 0;
		}
	}
	out[r] = '\0';
	return 0;
}