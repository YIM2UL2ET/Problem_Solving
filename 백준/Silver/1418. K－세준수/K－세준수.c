#include <stdio.h>

int main(void)
{
    int i, j, tmp, n, k, result = 0;
    scanf("%d %d", &n, &k);
    if (n >= 1) result++;
    for (i = 2; i <= n; i++)
    {
        tmp = i;
        j = 2;
        if (j > k) continue;
        while (tmp != 1)
        {
            if (tmp % j == 0) tmp /= j;
            else if (j+1 > k) break;
            else j++;
        }
        if (tmp == 1) result++;
    }
    printf("%d", result);
    return 0;
}