#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 256

char* randomWords(char* in, char* out)
{
	srand(time(NULL));
	char* arr[SIZE];
	int i = 0; //������� �������� � �������
	int j = 0;
	int n = 0; //������� ��� ����������� ������ ������������ ������
	char* S; //��������� �� ������� ����
	int inWord = 0; //������ - �� ������	
	char* element = out;
	while (*in)//������� ���������� ����� � ����������� �� � ������
	{
		if (*in != ' ' && inWord == 0) //���� ����� �����
		{
			arr[i] = in; //������ ������� ������� � ������� ���������
			i++;
			inWord = 1;
			n++;
		}
		else if (*in == ' ' && inWord == 1) //���� ������ �����������
		{
			inWord = 0;
		}
		in++; //������� � ���������� �������� � ������� ���������
	}
	for (i = n - 1; i >= 1;  i--) //������������� �������
	{		
		j = rand() % (i + 1);
		S = arr[j];
		arr[j] = arr[i];
		arr[i] = S;			
	}
	for (j = 0; j < n; j++) //����� ����������� �������
	{
		S = arr[j];
		while (*S != ' ' && *S != '\0')
		{
			*out = *S;
			S++;
			out++;
		}
		*out = ' ';
		out++;
	}
	out--;
	*out = 0;
	return element;
}

