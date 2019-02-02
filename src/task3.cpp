#include <time.h>
#include <stdlib.h>
#include <string.h>
#define COUNT_WORDS_MAX 20
#define LENGTH_WORDS_MAX 30

char *mixChars(char *in, char *out)
{
	int len = 0; // length of word
	while (*(in + len) != ' ' && *(in + len) != '\n' && *(in + len) != '\0')
	{
		*(out + len) = *(in + len);
		len++;
	}

	char temp = 0;
	int randNum = 0;
	for (int j = 1; j < len-1; j++)
	{
		temp = *(out+j);
		randNum = j + rand() % (len-1 - j);
		*(out + j) = *(out + randNum);
		*(out + randNum) = temp;
	}
	return out;
}

char *mixLine(char *instr, char * outstr)
{
	for (int i = 0; i <= strlen(instr); i++)
	{
		if (*(instr + i) != ' ' && *(instr + i) != '\0' && *(instr + i) != '\n' && (i == 0 || *(instr + i - 1) == ' '))
			mixChars(instr + i, outstr + i);
		else if (*(instr + i) == ' ' || *(instr + i) == '\0'|| *(instr + i) == '\n')
			*(outstr + i) = *(instr + i);
	}
	return outstr;
}