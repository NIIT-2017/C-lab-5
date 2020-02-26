#include"task3.h"
#include<string.h>
#include<time.h>
#include<stdlib.h>

char *mixChars(char *in, char *out)
{
    int i=0;
    while(*(in+i)!=' '&&*(in+i)!='\n'&&*(in+i)!='\0')
    {
       *(out+i)=*(in+i);
       i++;
    }
    char ch=0;
    int value=0;
    for(int j=1;j<i-1;j++)
    {
      ch=*(out+j);
      value=j+rand()%(i-1-j);
      *(out+j)=*(out+value);
      *(out+value)=ch;
    }
    return out;
}
char *mixLine(char *instr, char *outstr)
{
  for(int i=0; i<=strlen(instr);i++)
  {
    if(*(instr+i)!=' '&&*(instr+i)!='\0'
       && *(instr+i)!='\n'&&(i==0||*(instr+i-1)==' '))
    mixChars(instr+i,outstr+i);
    else if(*(instr+i)=='\n'||*(instr+i)=='\0'||*(instr+i)==' ')
      *(outstr+i)=*(instr+i);
  }
  return outstr;
}
