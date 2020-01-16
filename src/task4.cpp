#include "task4.h"

#define printf //

char* randomWords(char* instr, char* outstr) {
	int i = 0, inWord = 0, n = 0;
	char* pWord[NLINES_MAX] = { NULL };
	char tmpstr[LEN_MAX] = { 0 };

	// Определение начальных адресов(указателей) каждого слова в каждой строке
	while (instr[i]) {
		if (instr[i] != ' ' && instr[i] != '\n' && instr[i] != '\0' && inWord == 0) {	//начало слова
			inWord = 1;
			pWord[n] = &instr[i];
			printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			printf("&instr[%d] = %p\n", i, &instr[i]);
			printf("&instr[%d] = %s\n", i, &instr[i]);
			printf("pWord[%d] --> %p\n", n, pWord[n]);
			printf("pWord[%d] --> %s\n", n, pWord[n]);
			n++;
		}
		else if (instr[i] == ' ' && inWord == 1) {	//конец слова
			inWord = 0;
		}
		else if ((instr[i] == '\n' || instr[i] == '\0')) {	//конец строки
			inWord = 0;
		}
		i++;
	}

	printf("Количество слов n --> %d\n", n);
	printf("########################################\n");
	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		int j = rand() % (n - i);
		printf("****************************************\n");
		printf("pWord[rand = %d] --> %s\n", j, pWord[j]);
		printf("pWord[%d] --> %p\n", i, pWord[i]);
		printf("pWord[%d] --> %s\n", i, pWord[i]);
		char* tmp = pWord[j];
		pWord[j] = pWord[i];
		pWord[i] = tmp;
		printf("pWord[%d] --> %p\n", i, pWord[i]);
		printf("pWord[%d] --> %s\n", i, pWord[i]);
		printf("****************************************\n");
	}

	int j = 0;
	for (int i = 0; i < n; i++) {
		char* nWord = pWord[i];
		printf("pWord[%d] = %p\n", i, pWord[i]);
		printf("pWord[%d] = %s\n", i, pWord[i]);
		printf("nWord = %p\n", nWord);
		printf("nWord = %s\n", nWord);

		while (nWord && (*nWord != ' ' && *nWord != '\0')) {
			outstr[j] = *nWord++;
			j++;
		}
		outstr[j++] = ' ';
		printf("outstr --> %s\n", outstr);
	}
	outstr[j] = '\0';
	outstr[j - 1] = '\0';
	printf("outstr = %s\n", outstr);

	return outstr;
}