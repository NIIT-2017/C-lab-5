/*    Ќаписать программу, котора€ принимает от пользовател€ строку и
выводит ее на экран, перемешав слова в случайном пор€дке.*/

#include "task1.h"

int main() {
	char str[WORDS] = { };
	char out[WORDS] = { };

	//************************Enter str***************************
	printf("Enter sentense (max %d letters):\n", WORDS);
	for (int i = 0; i < WORDS; i++) {
		str[i] = getchar();
		if (str[i] == '\n') {
			str[i] = '\0';
			break;
		}
	}

	//***************Sorting_and_printing_str*********************
	randomWords(str, out);
	puts(out);
	return 0;
}