#define _CRT_SECURE_NO_WARNINGS
#define STR 4
#include <stdio.h>
#include <string.h>
#include "task3.h"
#include <time.h>


int main(int argc, char * argv[])
{
	char buf[256];					//храним строки из txt
	char out[256] = {0};					//храним строки из txt
	if (argc < 2)		
	{
		printf("Wrong format\n");
		return -1;
	}

	FILE *fr = fopen(argv[1], "rt");	//открывать файл на чтение
	if (!fr)
	{
		printf("Cannot open %s\n", argv[1]);
		return -1;
	}
	printf("Strings from txt:\n\n");
	int i = 0;
	while (!feof(fr))					//читаем файл и записываем в буфер
	{
		fgets(buf, 256, fr);
		printf("%s", buf);

		mixLine(buf, out);		//перемешивание для целой строки

		printf("New strings\n");			//вывод новой строки
		printf("%s\n", out);

		i++;		
		
	}
	printf("\n\n");
	fclose(fr);							//закрыли поток
	
	return 0;
}