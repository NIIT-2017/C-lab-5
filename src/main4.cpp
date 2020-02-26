#include"task1.h"
#include<stdio.h>
#include<stdlib.h>
#define N 256

int main(void)
{
  char in[N]={0};
  char out[N]={0};
  FILE *fb;
  fb=fopen("Myfile.txt","rb");
  if(fb==NULL)
  {
     puts("ERROR!");
     exit(1);
  }
  while(fgets(in,N,fb)!=NULL)
  puts(randomWords(in,out));
  return 0;
}
