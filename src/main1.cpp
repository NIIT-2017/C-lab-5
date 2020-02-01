//Clab5 task1

#include "task1.h"

int main()
{
	char in[SIZE];
	char out[SIZE];

	puts("Enter a line of words I will mix these words!");

	fgets(in, SIZE, stdin);
	
	printf("%s", randomWords(in, out));

	return 0;
}
