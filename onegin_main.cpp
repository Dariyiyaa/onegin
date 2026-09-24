#include <stdio.h>
#include <assert.h>

#include "ReadFile.cpp"
#include "PrintFile.cpp"
#include "SortFunc.cpp"


int main()
{   
    char  file_name[] = "onegin.txt";
    FILE* file_ptr   = fopen(file_name, "r");

    assert(file_ptr);

    int nchar = IndexCount(file_name);

    char*  text  = (char*)calloc(nchar, sizeof(size_t));
    char** lines_ptr = (char**)calloc(nchar, sizeof(size_t));

    int nlines = ReadFile(file_ptr, text, lines_ptr);

    qsort((void*)lines_ptr, nlines, sizeof(char*), &AlfavetComper);
    PrintFile(lines_ptr, nlines);


    qsort((void*)lines_ptr, nlines, sizeof(char*), &AlfavetBackwardComper);
    PrintFile(lines_ptr, nlines);

    fclose(file_ptr);
}