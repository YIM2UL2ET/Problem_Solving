#include <stdio.h>

int main(void)
{
    int count, n, m, i, j, x, y, k, sum;
    scanf("%d %d", &n, &m);
    int ary[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++) 
        {
            scanf("%d", &ary[i][j]);
        }
    }

    scanf("%d", &k);
    for (count = 0; count < k; count++)
    {
        sum = 0;
        scanf("%d %d %d %d", &i, &j, &x, &y);
        m = j;
        for (i; i <= x; i++)
        {
            for (j = m; j <= y; j++)
            {
                sum += ary[i-1][j-1];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}