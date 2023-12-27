#include <stdio.h>

int main(void)
{
    int i, n, sum = 0;
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &n);
        if(n < 40) n = 40;
        sum += n;
    }
    sum /= 5;
    printf("%d", sum);
    return 0;
}