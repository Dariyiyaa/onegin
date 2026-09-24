#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int AlfavetComper(const void* symbol1, const void* symbol2);
int AlfavetBackwardComper(const void* symbol1, const void* symbol2);
int LenSrt(const char* s);


int AlfavetComper(const void* symbol1, const void* symbol2)
{
    const char* s1 = *(char*const *)symbol1;
    const char* s2 = *(char*const *)symbol2;

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

int AlfavetBackwardComper(const void* symbol1, const void* symbol2)
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