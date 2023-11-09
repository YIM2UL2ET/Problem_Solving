#include <stdio.h>

long long padovan(int x);

int main(void)
{
    int i, n, x;
    long long y;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        y = padovan(x);
        printf("%lld\n", y);
    }
    return 0;
}

long long padovan(int x)
{
    int i, j;
    long long ary[5] = {1,1,1,2,2};

    // i = 1~5 까지는 각 11122, i>5부터 ary[i] = ary[i-1] + ary[i-5]의 값을 누적

    if (x <= 5) return ary[x-1];

    for (i = 6; i <= x; i++)
    {
        ary[(i-1)%5] += ary[(i-2)%5];
    }
    return ary[(i-2)%5];
}