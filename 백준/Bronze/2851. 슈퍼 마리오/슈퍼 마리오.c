#include <stdio.h>
#include <math.h>

int main(void)
{
    int ary[10];
    int i, sum = 0;
    for (i = 0; i < 10; i++) scanf("%d", &ary[i]);
    for (i = 0; i < 10; i++)
    {
        if (abs(100 - sum) >= abs(100 - sum - ary[i])) sum += ary[i];
        else break;
    }
    printf("%d", sum);
    return 0;
}