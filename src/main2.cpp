#include"task2.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10
#define M 20

int main(void)
{
  char arr[N][M]={0};
  srand(time(NULL));
  while(1)
  {
     clearMatrix(arr);
     fillMatrix(arr);
     setMatrix(arr);
     system("cls");
     printMatrix(arr);
     clock_t t=clock();
     while(clock() < t +CLOCKS_PER_SEC);
  }
  return 0;
}
