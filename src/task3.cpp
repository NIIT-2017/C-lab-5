#include <string.h>
#include <stdlib.h>
void CleanMass(char *in)//clean massiv
{
	for (int i = 0; in[i] != '\0'; i++)
		in[i] = '\0';
}
char *mixChars(char *in, char *out)// -перемешивание символов в одном слове
{
	int size = strlen(in);
	if (size > 3)
	{
		char temp;
		int random = 0;
		int flag = 0;
		if (in[0] == ' ')
			flag = 2;
		else
			flag = 1;
		for (int i = flag; in[i+1]!='\0'; i++)
		{
			random = flag + rand() % (size - 3);
			temp = in[random];
			in[random] = in[i];
			in[i] = temp;
		}
	}
		
	return out;
}
char *mixLine(char *instr, char * outstr)// -перемешивание для целой строки
{
	char in[30] = { NULL };
	char out[1] = { NULL };
	int incount = 0, count = 0, outcount=0;
	do
	{
		in[count] = instr[incount];//instr->in
		count++;
		if (instr[incount+1] == ' '||instr[incount+1] == '\0'|| instr[incount + 1] == '\n')//word end
		{
			mixChars(in, out);//in->out
			count = 0;
			while (in[count] != '\0')//out->outstr
			{
				outstr[outcount] = in[count];
				count++;
				outcount++;
			}
			count = 0;
			CleanMass(in);
		}
		incount++;
	} while (instr[incount] != '\0');
	return outstr;
}