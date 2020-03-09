#include"task1.h"
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define N 30

char *randomWords(char *in,char *out)
{
   if(in[strlen(in)-1]=='\n')
        in[strlen(in)-1]='\0';
   char *buf[N];
   int flag=0,i=0,count=0;
   while(in[i]!='\0')
   {
      if(flag==0 && in[i] !=' ')
      {
	flag=1;buf[count]=&in[i];count++;
      }
      if(in[i]==' ')
      {
	flag=0;
      }
      i++;
   }
   int j=0;
   while(count!=0)
   {
      i =rand()%count;
      char *p_01 =buf[i];
      while(*p_01 !='\0' && *p_01 !=' ')
      {
	out[j] =*p_01++;
	j++;
      }
      out[j++]=' ';
      char *p_02 =buf[i];
      buf[i]=buf[count-1];
      buf[count-1]=p_02;
      count--;
   }
   out[strlen(out)-1]='\0';
   return out;
}
