#include <stdio.h>
#include <sys/stat.h>

int IndexCount(char* file_ptr);
int ReadFile(FILE* file_ptr, char* text, char** lines_ptr);


int IndexCount(char* file_ptr)
{
    struct stat buff;
    stat(file_ptr, &buff);

    return buff.st_size;
}

int ReadFile(FILE* file_ptr, char* text, char** lines_ptr)
{
    int symbol_count = 0, lines_count = 0;
    int symbol = 0;

    while((symbol = getc(file_ptr)) != EOF)
    {
        text[symbol_count] = (char)symbol;
        
        if ((char)symbol == '\n')
        {
            lines_ptr[lines_count] = text + symbol_count + 1;
            lines_count++;
        }

        symbol_count++;
    }

    return lines_count;
}