#include <stdio.h>

int main(void)
{
    int i, n, sum = 0, min = 100;
    for (i = 0; i < 7; i++)
    {
        scanf("%d", &n);
        if(n % 2 == 1)
        {
            sum += n;
            if (n < min) min = n;
        }
    }
    if(sum == 0) printf("-1");
    else printf("%d\n%d", sum, min);
    return 0;
}