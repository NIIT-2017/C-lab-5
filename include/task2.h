#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void clearMatrix(char(*arr)[SIZE]); //���������� ���������� �������(�������) ���������
void fillMatrix(char(*arr)[SIZE]);  //���������� �������� ������ ��������� ������� �����������
void setMatrix(char(*arr)[SIZE]);   //����������� ��������� � ������ ������� �������
void printMatrix(char(*arr)[SIZE]); //������ �������
