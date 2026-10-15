#include <stdio.h>
#include <sys/stat.h>

int IndexCount(char* file_ptr);
int ReadFile(FILE* file_ptr, char* text, char** lines_ptr);


int IndexCount(char *const file_ptr)
{
    struct stat buff;
    stat(file_ptr, &buff);

    return buff.st_size;
}

int ReadFile(FILE *const file_ptr, char* text, char** lines_ptr)
{
    int symbol_count = 0, lines_count = 0;
    int symbol = 0;

    int string_start = 0;

    while((symbol = getc(file_ptr)) != EOF)
    {
        string_start = symbol_count;

        while ((symbol = getc(file_ptr)) != '\n')
        {
            text[symbol_count] = (char)symbol;
            symbol_count++;
        }
        
        lines_ptr[lines_count] = text + string_start;
        lines_count++;
    }

    return lines_count;
}