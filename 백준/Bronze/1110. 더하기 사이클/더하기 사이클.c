#include <stdio.h>

int main(void)
{
    int n, i, s = -1;
    scanf("%d", &n);
    int originalNum = n;

    for (i = 0; originalNum != s; i++)
    {
        s = n % 10 + n / 10;
        if (s >= 10) s %= 10;
        s += n % 10 * 10;
        n = s;
    }
    printf("%d", i);
    return 0;
}