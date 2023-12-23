#include <stdio.h>

int main(void)
{
    long long i, n;
    scanf("%lld", &n);
    for (i = 1; n - i >= 0; i++)
    {
        n -= i;
    }
    printf("%lld", i-1);
    return 0;
}