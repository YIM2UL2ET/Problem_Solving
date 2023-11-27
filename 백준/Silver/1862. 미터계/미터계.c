#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, n, result = 0;
    scanf("%d", &n);
    for (i = 0; n > 0; i++)
    {
        if (n % 10 > 4) result += (n % 10 - 1) * (int)(pow(9,i));
        else result += n % 10 * (int)(pow(9,i));
        n /= 10;
    }
    printf("%d", result);
    return 0;
}