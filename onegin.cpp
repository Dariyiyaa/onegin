#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>

int  IndexCount(char* file);
int  PrintFile(char** index, int nlines);
void PrintString(FILE* file, char* index);
int  ReadFile(FILE* name, char* text, char** index);
int  AlfavetComper(const void* a, const void* b);
int  AlfavetBackwardComper(const void* a, const void* b);

int IndexCount(char* file)
{
    struct stat buff;
    stat(file, &buff);

    return buff.st_size;
}

int ReadFile(FILE* file, char* text, char** index)
{
    int i = 0, j = 0;
    int c = 0;

    while((c = getc(file)) != EOF)
    {
        text[i] = (char)c;

        if ((char)c == '\n')
        {
            index[j] = text + i + 1;
            j++;
        } 
        i++;
    }

    return j;
}

void PrintString(FILE* file, char* index)
{
    int i = 0;

    while ((*(index + i) != '\n') && (*(index + i) != '\0'))
    {
        putc(*(index + i), file);
        i++;
    }
    
    putc('\n', file);
    
    return;
}

int PrintFile(char** index, int nlines)
{
    FILE* file = fopen("output.txt", "w");

    for (int i = 0; i < nlines; i++)
    {
        PrintString(file, index[i]);
    }
    
    return 0;
}

int AlfavetComper(const void* a, const void* b)
{
    return strcmp(*(char*const *)a, *(char*const *)b);
}


int AlfavetBackwardComper(const void* a, const void* b)
{
    return -strcmp(*(char*const *)a, *(char*const *)b);
}


int main()
{   
    char path[] = "onegin.txt";
    FILE* file = fopen(path, "r");

    assert(file);

    int nchar = IndexCount(path);

    char* text = (char*)calloc(nchar, sizeof(size_t));
    char** index = (char**)calloc(nchar, sizeof(size_t));

    int nlines = ReadFile(file, text, index);


    PrintFile(index, nlines);


    fclose(file);
}
