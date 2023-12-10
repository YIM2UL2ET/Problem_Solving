#include <stdio.h>

int main(void)
{
    int i, n, sum, tmp;
    scanf("%d", &n);

    for (i = 1; i < n; i++)
    {
        sum = i;
        tmp = i;
        while (tmp != 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        
        if (sum == n)
        {
            printf("%d", i);
            return 0;
        }
    }

    printf("0");
    return 0;
}