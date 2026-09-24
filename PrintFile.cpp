#include <stdio.h>
#include <stdlib.h>

void PrintString(FILE* file_ptr, char* lines_ptr);
int  PrintFile(char** lines_ptr, int nlines);


void PrintString(FILE* file_ptr, char* lines_ptr)
{
    int i = 0;

    while ((*(lines_ptr + i) != '\n') && (*(lines_ptr + i) != '\0'))
    {
        putc(*(lines_ptr + i), file_ptr);
        i++;
    }
    
    putc('\n', file_ptr);
    
    return;
}

int PrintFile(char** lines_ptr, int nlines)
{
    char filename[50] = "";
    int file_id = rand() % 10;

    sprintf(filename, "output%d.txt", file_id);

    FILE* output = fopen(filename, "w");

    for (int lines_count = 0; lines_count < nlines; lines_count++)
    {
        PrintString(output, lines_ptr[lines_count]);
    }
    
    fclose(output);

    return 0;
}