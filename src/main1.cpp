#include"task1.h"
#include<stdio.h>
#include<stdlib.h>
#define N 256

int main(void)
{
  char in[N]={0};
  char out[N]={0};
  printf("Enter the string!\n");
  fgets(in,N,stdin);
  puts("");
  printf("Random word in the string!\n");
  printf("%s\n",randomWords(in,out));
  return 0;
}
