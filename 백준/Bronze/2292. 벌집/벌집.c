#include <stdio.h>

int main(void)
{
    int n, i, sum = 1;
    scanf("%d", &n);
    for (i = 1; sum < n; i++)
    {
        sum += i * 6;
    }
    printf("%d", i);
    return 0;
}