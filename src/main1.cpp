#include "task1.h"

int main() {
	setlocale(LC_ALL, "russian");

	char in[LEN_MAX] = { 0 };
	char out[LEN_MAX] = { 0 };

	printf("¬ведите несколько слов в строке:\n");
	fgets(in, LEN_MAX, stdin);
	if (*in != 0 && in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';

	printf("–езультат: %s\n", randomWords(in, out));

}
