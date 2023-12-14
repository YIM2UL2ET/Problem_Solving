#include <stdio.h>
#include <stdlib.h>

int static compare (const void* pa, const void* pb);

int main(void)
{
    int n, i, tmp;
    long long max = 0;
    scanf("%d", &n);
    
    int ary[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ary[i]);
    }

    qsort(ary, n, sizeof(int), compare);

    for (i = 0; i < n; i++)
    {
        tmp = ary[i] * (i + 1);
        if (tmp > max) max = tmp;
    }
    
    printf("%lld", max);
    
    return 0;
}

int static compare (const void* pa, const void* pb)
{
    if (*(int*)pa < *(int*)pb) return 1;
    else if (*(int*)pa > *(int*)pb) return -1;
    else return 0;
}