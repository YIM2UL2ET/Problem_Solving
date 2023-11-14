#include <stdio.h>

int main(void)
{   
    int i, j, x, sum = 0;
    scanf("%d", &x);
    for (i = 1; x > sum + i; i++)
    {
        sum += i;
    }

    x -= sum;
    i++;

    if (i % 2 == 0)
    {
        for (j = 0; j < x; j++){}
        printf("%d/%d", i-j, j);
    }

    else
    {   
        for (j = 0; j < x; j++){}
        printf("%d/%d", j, i-j);
    }

    return 0;
}