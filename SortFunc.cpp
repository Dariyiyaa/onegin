#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COMPARE(s1, s2) if (s1 < s2) return -1; else if (s1 == s2) return 0; else return 1;

int AlfaveticOrder(const void* symbol1, const void* symbol2);
int BackwardOrder(const void* symbol1, const void* symbol2);
int OriginalText(const void* symbol1, const void* symbol2);
int LenSrt(const char* s);


int OriginalText(const void* symbol1, const void* symbol2)
{
    const char* s1 = *(char *const *)symbol1;
    const char* s2 = *(char *const *)symbol2;

    COMPARE(s1, s2)
}


int AlfaveticOrder(const void* symbol1, const void* symbol2)
{
    const char* s1 = *(char *const *)symbol1;
    const char* s2 = *(char *const *)symbol2;

    return strcmp(s1, s2);
}

int LenSrt(const char* s)
{
    int len = 0;
    while (*(s + len) != '\n' && *(s + len) != '\0')
    {
        len++;
    }    

    return len;
}

int BackwardOrder(const void* symbol1, const void* symbol2)
{   
    const char* s1 = *(char*const *)symbol1;
    const char* s2 = *(char*const *)symbol2;

    int len_s1 = LenSrt(s1) - 1;
    int len_s2 = LenSrt(s2) - 1;
    
    while(len_s1 >= 0 && len_s2 >= 0)
    {
        if (s1[len_s1] != s2[len_s2])
        {
            return s1[len_s1] - s2[len_s2];
        }

        len_s1--;
        len_s2--;
    }

    return len_s1 - len_s2;
}