#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, j, answer, sameHeight;

    scanf("%d", &n);
    int ary[n];
    answer = n;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &ary[i]);
    }

    for (i = 1; i <= 1000; i++)
    {
        sameHeight = 0;
        for (j = 0; j < n; j++)
        {
            if (ary[j] == i) sameHeight++;
        }
        if (sameHeight > 2) answer -= sameHeight - 2;
    }

    printf("%d", answer);
    return 0;
}