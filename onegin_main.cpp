#include <stdio.h>
#include <assert.h>

#define SORT_AND_PRINT(s) qsort((void*)lines_ptr, nlines, sizeof(char*), &s); PrintFile(lines_ptr, nlines,output_file_ptr);

#include "ReadFile.cpp"
#include "PrintFile.cpp"
#include "SortFunc.cpp"


int main(int argc, char* argv[])
{   
    if (argc < 3)
    {
       fprintf(stderr, "argc < 3\n"); 
       return 0;
    }

    FILE* output_file_ptr = fopen(argv[2], "w");

    char* file_name = argv[1];
    FILE* file_ptr   = fopen(file_name, "r");

    assert(file_ptr);

    size_t nchar = IndexCount(file_name);

    char*  text  = (char*)calloc(nchar, sizeof(size_t));
    char** lines_ptr = (char**)calloc(nchar, sizeof(size_t));

    size_t nlines = ReadFile(file_ptr, text, lines_ptr);

    SORT_AND_PRINT(AlfaveticOrder)

    SORT_AND_PRINT(BackwardOrder)

    SORT_AND_PRINT(OriginalText)

    fclose(file_ptr);
    fclose(output_file_ptr);

}