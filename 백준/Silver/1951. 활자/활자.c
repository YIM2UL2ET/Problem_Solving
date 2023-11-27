#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    long long n, tmp = 9, sum = 0;
    scanf("%lld", &n);
    for (i = 1; tmp <= n; i++)
    {
        sum += i * tmp; 
        n -= tmp;
        tmp *= 10;
        sum %= 1234567;
    }
    sum += n * i;
    sum %= 1234567;

    printf("%lld", sum);
    return 0;
}