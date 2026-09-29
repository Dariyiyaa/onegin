#include <stdio.h>
#include <stdlib.h>

void PrintString(FILE* file_ptr, char *const lines_ptr);
int  PrintFile(char *const *const lines_ptr, const size_t nlines);


void PrintString(FILE* const file_ptr, char *const lines_ptr)
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

int PrintFile(char *const *const lines_ptr, const size_t nlines)
{
    FILE* output = fopen("output.txt", "a");

    for (size_t lines_count = 0; lines_count < nlines; lines_count++)
    {
        PrintString(output, lines_ptr[lines_count]);
    }

    putc('\n', output);
    
    fclose(output);

    return 0;
}