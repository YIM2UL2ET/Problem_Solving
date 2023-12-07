#include <stdio.h>

int main(void)
{
    int result = 1, n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    while((a+1) / 2 != (b+1) / 2)
    {
        a = (a+1) / 2;
        b = (b+1) / 2;
        result++;
    }
    printf("%d", result);
    return 0;
}