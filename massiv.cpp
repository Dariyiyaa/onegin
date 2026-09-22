#include <stdio.h>

int main()
{
    int s[10][10] = {};


    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if (i >= j)
            {
                printf("%d\t",s[i][j]);
            }
        }
        printf("%c", '\n');
    }
}