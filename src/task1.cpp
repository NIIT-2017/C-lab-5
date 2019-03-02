#include "task1.h"

char * randomWords(char * in, char * out) {
	char * index[WORDS];
	int flag = 0, word = 0, temp = 0, end_string = 0;

	for (int u = 0; u < strlen(in); u++) {
		if (in[u] == '\n')
			in[u] = '\0';
	}

	for (int i = 0; i < strlen(in); i++) {										//Расстановка указателей на первые буквы в словах
		if (in[i] == ' ' && flag == 1)											//Проверка на окончание слова
			flag = 0;
		if (in[i] != ' ' && flag == 0) {										//Проверка начала нового слова
			index[word++] = &in[i];
			flag = 1;
		}
	}

	char spase[WORDS] = { '\0' };
	srand(time(0));
	for (int i = 0; i < word; i++) {											//Повторять, пока не используем все слова
			do {
				temp = rand() % word;											//Выбор случайного указателя на слово
				if (index[temp] != NULL) {										//Проверка на использование данного слова
					for (int j = 0; *index[temp]; j++) {						//Получение строки, начинающейся с этого слова
						spase[j] = *index[temp]++;
						if (*index[temp] == ' ' || *index[temp] == '\0') {		//Вырезание отдельного слова, на которое ссылается указатель
							spase[j + 1] = '\0';
							break;
						}
					}
					strcat(out, spase);											//Добавление слова к изменённой строке
					out[strlen(out)] = ' ';										//Добавление пробела после этого слова
					index[temp] = NULL;											//Обнуление указателя на использованное слово
					break;
				}
			} while (1);
		}
		out[strlen(out)] = '\0';												//Установка конца изменённой строки
	return out;
}