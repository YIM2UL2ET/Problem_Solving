#include <stdio.h>

int main(void)
{
    int i, n;
    long long sum = 0;
    scanf("%d", &n);

    int ary[n];
    for (i = 0; i < n; i++) scanf("%d", &ary[i]);

    sum += ary[0] + ary[n-1] + n * 2;
    for (i = 0; i < n-1; i++)
    {
        sum += ary[i] * 2;
        if (ary[i] - ary[i+1] < 0) sum -= ary[i] - ary[i+1];
        else sum += ary[i] - ary[i+1];
    }
    sum += ary[n-1] * 2;

    printf("%lld", sum);
    return 0;
}