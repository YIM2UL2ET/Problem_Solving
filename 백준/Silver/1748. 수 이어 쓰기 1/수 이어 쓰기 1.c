#include <stdio.h>

int main(void)
{
    int i, n, tmp = 9;
    long long sum = 0;
    scanf("%d", &n);
    for (i = 1; n > tmp; i++)
    {
        n -= tmp;
        sum += tmp * i;
        tmp *= 10;
    }
    sum += n * i;

    printf("%lld", sum);
    return 0;
}