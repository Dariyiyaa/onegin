#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int  ReadFile(const char* name, char* index[1000]);
int  PrintFile(char* index[1000], int nlines);
void PrintString(char* index);
void SortStrings(char* index[1000], int nlines);
// void SwitchIndex(char** index1, char** index2);
// void SortStringsBackward(char* index[1000], int nlines);
int  AlfavetComper(const void* a, const void* b);
int  AlfavetBackwardComper(const void* a, const void* b);
void Free(char** index, int nlines);

int IndexCount(char* name)
{
    FILE* file = fopen(name, "r");
    int i = 0;
    while (getc(file) != EOF)
    {
        i++;
    }

    return i;
    fclose(file);
}

int ReadFile(const char* name, char** index)
{
    FILE* file = fopen(name, "r");
    int i = 0;
    char buffer[1000] = {};

    while (fgets(buffer, 1000, file) != NULL)
    {
        index[i] = (char*)calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(index[i], buffer);
        i++;
    }

    fclose(file);

    return i;
}

void PrintString(char* index)
{
    int i = 0;
    while (*(index + i) != '\0')
    {
        printf("%c", *(index + i));
        i++;
    }
    // printf("%c", '\n');
    
    return;
}

int PrintFile(char** index, int nlines)
{
    for (int i = 0; i < nlines; i ++)
    {
        PrintString(index[i]);
    }

    printf("%c", '\n');
    return 0;
}

// void SwitchIndex(char** index1, char** index2)
// {
//     char* temp = *index1;
//     *index1 = *index2;
//     *index2 = temp;

//     return;
// }



// void SortStrings(char** index, int nlines)
// {
//     for (int i = 0; i < nlines; i ++)
//     {
//         for (int j = 1; j < nlines - i; j ++)
//         {
//             if (strcmp(index[j-1], index[j]) > 0)
//             {
//                 SwitchIndex(&index[j-1], &index[j]);
//             }
//         }
//     }

//     return;
// }


int AlfavetComper(const void* a, const void* b)
{
    return strcmp(*(char*const *)a, *(char*const *)b);
}


int AlfavetBackwardComper(const void* a, const void* b)
{
    return -strcmp(*(char*const *)a, *(char*const *)b);
}


void Free(char** index, int nlines)
{
    for (int i = 0; i < nlines; i ++)
    {
        free(index[i]);
    }

    return;
}

// void SortStringsBackward(char* index[1000], int nlines)
// {
//     for (int i = nlines; i > 0; i--)
//     {
//         for (int j = nlines; j > 0; j--)
//         {
//             if (strcmp(index[j], index[j-1]) > 0)
//             {
//                 SwitchIndex(&index[j-1], &index[j]);
//             }
//         }
//     }

//     return;
// }


int main()
{   
    char* index[100] = {};
    int nlines = IndexCount("smallonegin.txt");
    ReadFile("smallonegin.txt", index);

    PrintFile(index, nlines);

    qsort((void*) index, nlines, sizeof(char*), &AlfavetComper);
    PrintFile(index, nlines);

    qsort((void*) index, nlines, sizeof(char*), &AlfavetBackwardComper);
    PrintFile(index, nlines);

    Free(index, nlines);
}
