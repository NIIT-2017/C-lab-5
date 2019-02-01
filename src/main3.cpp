#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include "task3.h"
using namespace std;

int main()
{
	char instr[256], outstr[256];
	char filename[] = "input.txt";
	FILE *fp;
	if ((fp = fopen(filename, "rt")) == NULL)
	{
		printf("file open error\n");
		return 0;
	}
	while (fgets(instr, 256, fp)!=NULL)
		printf("%s", mixLine(instr,outstr));
	
	return 0;
}