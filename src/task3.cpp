#include "task3.h"

#define printf //

char* mixChars(char* in, char* out) {
	printf("****************************************************\n");
	printf("in ==> %s\n", in);
	int randNum = 0;
	int wordLen = 0;
	int i = 0;

	i = 0;
	while (in[i]) {
		if (in[i] != ' ' && in[i] != '\n' && in[i] != '\0') {
			printf("in[%d] --> %c\n", i, in[i]);
			out[i] = in[i];
			printf("out[%d] --> %c\n", i, out[i]);
			wordLen++;
		}
		else {
			break;
		}
		i++;
	}

	//srand(time(NULL));
	
	printf("wordLen --> %d\n", wordLen);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	srand(time(NULL));
	if (wordLen > 3) {
		for (int i = 1; i < wordLen - 1; i++) {
			randNum = rand() % (wordLen - i - 1);
			while (randNum == i) {
				randNum = rand() % (wordLen - i - 1);
			}
			printf("randNum = %d\n", randNum);
			printf("out[%d] --> %c\n", randNum, out[randNum]);
			char temp = out[i];
			out[i] = out[randNum];
			out[randNum] = temp;
			printf("out[%d] --> %c\n", i, out[i]);
		}
	}
	
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("out ===> %s\n", out);

	return out;
}

//**************************************************************************

char* mixLine(char* instr, char* outstr) {

	int i = 0, inWord = 0, n = 0;
	char* pWord[NLINES_MAX] = { NULL };
	char tmpstr[LEN_MAX] = { 0 };

	printf("mixLine instr = %s\n", instr);
// Определение начальных адресов(указателей) каждого слова в каждой строке
	while (instr[i]) {
		if (instr[i] != ' ' && instr[i] != '\n' && instr[i] != '\0' && inWord == 0) {	//начало слова
			inWord = 1;
			printf("&instr[%d] = %s\n", i, &instr[i]);
			mixChars(&instr[i], &tmpstr[i]);
			pWord[n] = &tmpstr[i];
			printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			printf("&tmpstr[%d] = %p\n", i, &tmpstr[i]);
			printf("&tmpstr[%d] = %s\n", i, &tmpstr[i]);
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

	printf("After mixChars tmpstr ===> %s\n", tmpstr);
	printf("Количество слов n --> %d\n", n);
	printf("########################################\n");

	//srand(time(NULL));

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
	printf("outstr = %s\n", outstr);

	return outstr;
}
