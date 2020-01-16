#include "task3.h"

int main() {
	setlocale(LC_ALL, "russian");

	char instr[LEN_MAX] = { 0 };
	char outstr[LEN_MAX] = { 0 };

	int n = 0;

	FILE* fp;
	if (!(fp = fopen("in.txt", "r"))) {
		puts("Ошибка открытия файла in.txt!\n");
		return 1;
	}

	while (fgets(instr, LEN_MAX, fp)) {
		//printf("instr = %s\n", instr);
		mixLine(instr, outstr);
		printf("%s\n", outstr);
	}
	printf("\n");

	fclose(fp);

	return 0;

}
