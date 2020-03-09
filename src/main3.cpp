#include"task3.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 256

int main(void)
{
  FILE *in;
  FILE *out;
  char arr1[N]={0};
  char arr2[N]={0};
  srand(time(NULL));
  in =fopen("first.txt","rb");
  if(in==NULL)
  {
     puts("Error!");
     exit(1);
  }
  out =fopen("result.txt","wb");
  if(out==NULL)
  {
    puts("ERROR!");
    exit(1);
  }
  while(fgets(arr1,N,in)!=NULL)
  fputs(mixLine(arr1,arr2),out);
  fclose(in);
  fclose(out);
  return 0;
}
