#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(size_t size, void* value1, void* value2);
int  CompareUp(void* a, void* b);
int  CompareDown(void* a, void* b);
void BubbleSort(void* ptr, size_t len, size_t size, int(*CompareFunc)(void* a, void* b));


void Swap(size_t size, void* const value1, void* const value2)
{
    void* temp = calloc(1, size);
    
    memcpy(temp, value1, size);
    memcpy(value1, value2, size);
    memcpy(value2, temp, size);

    return;
}


int CompareUp(void* a, void* b)
{
    if (*(int*)a > *(int*)b) return 1;
    if (*(int*)a == *(int*)b) return 0;
    if (*(int*)a < *(int*)b) return -1;
}

int CompareDown(void* a, void* b)
{
    return *(int*)b - *(int*)a;
}


void BubbleSort(void* ptr, size_t len, size_t size, int(*CompareFunc)(void* a, void* b))
{
    for (size_t j = 0; j < len; j++)
    {
        for (size_t i = 1; i < len - j; i++)
        {
            if (CompareFunc((char*)ptr + size*(i - 1), (char*)ptr + size*i) > 0)
            {
                Swap(size, (char*)ptr + size*(i - 1), (char*)ptr + size*i);
            }

            // for (size_t k = 0; k < len; k++)
            // {
            //     printf("%d\t", *((int*)ptr + k));
            // }
            // printf("%c",'\n');
        }
    }
    return;
}




int main()
{
    size_t size = 0;
    scanf("%zu", &size);
    
    int* ptr = (int*)calloc(size, sizeof(int));

    for (size_t i = 0; i < size; i++)
    {
        scanf("%d", ptr + i);
    }
    
    BubbleSort((void*)ptr, size, sizeof(ptr[0]), &CompareUp);

    for (size_t i = 0; i < size; i ++)
    {
        printf("%d\t", ptr[i]);
    }

    printf("%c", '\n');
    BubbleSort((void*)ptr, size, sizeof(ptr[0]), &CompareDown);

    for (size_t i = 0; i < size; i ++)
    {
        printf("%d\t", ptr[i]);
    }

    free(ptr);
}
