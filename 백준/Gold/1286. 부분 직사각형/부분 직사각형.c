#include <stdio.h>

int sequence_sum(int maxnum, int repeats);

int main(void)
{
    int i, j, n, m, sum = 0;
    long long alphaNumAry[26] = {0};

    scanf("%d %d", &n, &m);
    char squre[n][m];
    for (i = 0; i < n; i++) scanf("%s", &squre[i]);
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            sum += sequence_sum(i+1, n*2) * sequence_sum(j+1, m*2);
            sum += sequence_sum(n-i, n*2) * sequence_sum(j+1, m*2);
            sum += sequence_sum(i+1, n*2) * sequence_sum(m-j, m*2);
            sum += sequence_sum(n-i, n*2) * sequence_sum(m-j, m*2);

            alphaNumAry[squre[i][j]-65] += sum;
            sum = 0;
        }
    }
    
    for (i = 0; i < 26; i++)
    {
        printf("%lld\n", alphaNumAry[i]);
    }

    return 0;
}

int sequence_sum(int maxnum, int repeats)
{
    int sum = 0, i;
    repeats /= 2;
    sum += (maxnum + 1) * maxnum / 2;
    sum += (repeats - maxnum) * maxnum;
    return sum*2;
}