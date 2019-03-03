#include "task3.h"

char *mixChars(char *in, char *out) {
	
	char * index[WORDS] = {NULL};
	int temp = 0, end_word = 0;
	
	end_word = strlen(in);
	if (end_word <= 3) {														//Если в слове не более 3-х букв, то не перемешиваем их
		for (int u = 0; u <= end_word; u++)
			out[u] = in[u];
			return out;
	}
	
	for (int chars = 1; chars <= (end_word - 2); chars++)						//Расставляем указатели на буквы со второй до предпоследней
		index[chars] = &in[chars];

	srand(time(NULL));
		out[0] = in[0];															//Оставляем первую букву
		for (int i = 1; i <= end_word - 2; i++) {								//Повторять, пока не используем все буквы со второй до предпоследней
			do {
				temp = 1 + rand() % (end_word - 1);								//Выбор случайного указателя на букву
				if (index[temp] != NULL) {										//Проверка на использование данной буквы
					out[i] = *index[temp];
					index[temp] = NULL;											//Обнуление указателя на использованную букву
					break;
				}
			} while (1);														//Завершаем цикл, если использовали указатель на случайную букву
		}
		out[end_word - 1] = in[end_word - 1];
		out[end_word] = '\0';
	return out;
}


char *mixLine(char *instr, char * outstr) {
	char spase[WORDS] = { '\0' };												//Массив для записи слова перед перемешиванием букв
	char rew_word[WORDS] = { '\0' };											//Слово с перемешанными буквами
	char * index[WORDS];
	int flag = 0, word = 0, temp = 0, end_string = 0;

	for (int u = 0; u < strlen(instr); u++) {
		if (instr[u] == '\n')
			instr[u] = '\0';
	}

	for (int i = 0; i < strlen(instr); i++) {									//Расстановка указателей на первые буквы в словах
		if (instr[i] == ' ' && flag == 1)										//Проверка на окончание слова
			flag = 0;
		if (instr[i] != ' ' && flag == 0) {										//Проверка начала нового слова
			index[word++] = &instr[i];
			flag = 1;
		}
	}

	srand(time(0));
	for (int i = 0; i < word; i++) {											//Повторять, пока не используем все слова
		do {
			for (int j = 0; *index[i]; j++) {									//Получение строки, начинающейся с этого слова
				spase[j] = *index[i]++;
				if (spase[j] == ' ' || spase[j] == '\0') {						//Вырезание отдельного слова, на которое ссылается указатель
					spase[j] = '\0';
					break;
				}
			}
			mixChars(spase, rew_word);
			strcat(outstr, rew_word);										//Добавление слова к изменённой строке
			outstr[strlen(outstr)] = ' ';									//Добавление пробела после этого слова
			index[temp] = NULL;												//Обнуление указателя на использованное слово
			break;
		} while (index[temp] == NULL);
	}
	outstr[strlen(instr)] = '\0';												//Установка конца изменённой строки
	return outstr;
}




//for (int i = 0; i < word; i++) {										//Повторять, пока не используем все слова
//	do {
//		temp = rand() % word;											//Выбор случайного указателя на слово
//		if (index[temp] != NULL) {										//Проверка на использование данного слова
//			for (int j = 0; *index[temp]; j++) {						//Получение строки, начинающейся с этого слова
//				spase[j] = *index[temp]++;
//				if (*index[temp] == ' ' || *index[temp] == '\0') {		//Вырезание отдельного слова, на которое ссылается указатель
//					spase[j + 1] = '\0';
//					break;
//				}
//			}
//			mixChars(spase, rew_word);
//			strcat(outstr, rew_word);									//Добавление слова к изменённой строке
//			outstr[strlen(outstr)] = ' ';								//Добавление пробела после этого слова
//			index[temp] = NULL;											//Обнуление указателя на использованное слово
//			break;
//		}
//	} while (index[temp] == NULL);
//}
//outstr[strlen(instr)] = '\0';											//Установка конца изменённой строки