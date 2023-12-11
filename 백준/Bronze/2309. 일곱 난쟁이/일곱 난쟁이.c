#include <stdio.h>
#include <stdlib.h>

int static compare (const void* first, const void* second);

int main(void)
{
    int height[9];
    int i, j, k , sum = 0;
    for (i = 0; i < 9; i++) scanf("%d", &height[i]);

    for (i = 0; i < 9; i++)
    {
        for (j = i+1; j < 9; j++)
        {
            for (k = 0; k < 9; k++)
            {
                if(k == i || k == j) continue;
                sum += height[k];
            }
            if (sum == 100) break;
            else sum = 0;
        }
        if (sum == 100) break;
    }
    
    height[i] = 100;
    height[j] = 100;

    qsort(height, 9, 4, compare);

    for (i = 0; i < 7; i++)
    {
        printf("%d\n", height[i]);
    }
    return 0;
}

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}