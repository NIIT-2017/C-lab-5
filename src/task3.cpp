#include "task3.h"
int getWordLen(char* string, int startPos)
{
    int count = startPos;
    while (string[count] != ' ' && string[count] != '\n' && string[count] != '\0')
    {
        count++;
    }
    return count - startPos;
}
char** readFile(FILE *file,int *linesNumber)
{
    int count = 0;
    char buf;
    while (fread(&buf,sizeof(char),1,file))
    {
        if (buf == '\n')
            count++;
    }
    *linesNumber = count;
    char** lines=(char**)malloc(count*sizeof(char*));
    rewind(file);
    for (int i = 0; i < count; i++)
    {
        int lineLen = 0;
        do
        {
            fread(&buf, sizeof(char), 1, file);
            lineLen++;
        } while (buf != '\0' &&buf!='\n');
        lineLen++;
        lines[i] = (char*)malloc(lineLen*sizeof(char));
        fseek(file, ftell(file) - lineLen, SEEK_SET);
        fgets(lines[i],100, file);
    }
    return lines;
}
char* mixChars(char* in, char* out)
{
    int len = strlen(out);
    int* randomArr = (int*)malloc(len * sizeof(int));
    randomArr[0] = 0;
    out[0] = in[0];
    out[len - 1] = in[len - 1];
    for (int i = 1; i < len-1; i++)
    {
        while (1)
        {
            randomArr[i] = rand() % (len-1);
            int alredyExists = 0;
            for (int j = 0; j < i; j++)
            {
                if (randomArr[i] == randomArr[j])
                {
                    alredyExists = 1;
                    break;
                }
            }
            if (!alredyExists)
                break;
        }
        out[i] = in[randomArr[i]];
    }
    return out;
}
char* mixLine(char* instr, char* outstr)
{
    int len = strlen(instr);
    for (int i = 0; i < len; i++)
    {
        if ((i == 0 && instr[i] != ' ') || (instr[i] != ' ' && instr[i - 1] == ' '))
        {
            int wordLen = getWordLen(instr, i);
            char* wordOut = (char*)malloc(wordLen * sizeof(char));
            for (int j = 0; j < wordLen; j++)
            {
                wordOut[j] = ' ';
            }
            wordOut[wordLen] = '\0';
            mixChars(&instr[i],wordOut);
            for (int j = 0; j < wordLen; j++)
            {
                outstr[j + i] = wordOut[j];
            }
        }
        else
        {
            if (instr[i] == ' ')
                outstr[i] = ' ';
            if (instr[i] == '\n')
                outstr[i] = '\n';
        }
    }
    outstr[len] = '\0';
    return outstr;
}