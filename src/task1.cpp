#include "task1.h"

#define printf //

char* randomWords(char* in, char* out) {
	int i = 0, inWord = 0, n = 0;
	char* pWord[LEN_NUM] = { NULL };

	while (in[i]) {
		if (in[i] != ' ' && inWord == 0) {	//начало слова
			inWord = 1;
			pWord[n] = &in[i];
			printf("%c\n", in[i]);
			printf("&in[%d] = %p\n", i, &in[i]);
			printf("pWord[%d] = %p\n", n, pWord[n]);
			printf("pWord[%d] = %s\n", n, pWord[n]);
			n++;

		}
		else if (in[i] == ' ' && inWord == 1) {	//конец слова
			inWord = 0;
		}
		i++;
	}

	printf("n --> %d\n", n);
	putchar('\n');

	srand(time(NULL));

	for (int i = n - 1; i >= 1; i--)
	{
		int j = rand() % (i + 1);
		printf("pWord[j = %d] --> %s\n", j, pWord[j]);
		char* tmp = pWord[j];
		pWord[j] = pWord[i];
		pWord[i] = tmp;
		printf("pWord[i = %d] --> %s\n", i, pWord[i]);
		printf("pWord[i = %d] --> %p\n", i, pWord[i]);
	}

	i = 0;
	while (n > 0) {
		char* nWord = pWord[n-1];
		printf("pWord[%d] = %p\n", n, pWord[n-1]);
		printf("nWord = %p\n", nWord);
		printf("nWord = %s\n", nWord);

		while (nWord && *nWord != ' ' && *nWord != '\0') {
			out[i++] = *nWord++;
		}
		out[i++] = ' ';
		n--;
	}
	out[i] = '\0';
	out[i - 1] = '\0';

	printf("out = %s\n", out);

	return out;
}