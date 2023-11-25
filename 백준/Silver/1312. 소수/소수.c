#include <stdio.h>

int main(void)
{
    int a, b, n, i, result;
    scanf("%d %d %d", &a, &b, &n);

    a %= b;
    for (i = 0; i < n; i++)
    {
        a *= 10;
        result = a / b;
        a %= b;
    }
    printf("%d", result);
    return 0;
}