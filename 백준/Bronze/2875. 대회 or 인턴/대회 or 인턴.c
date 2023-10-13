#include <stdio.h>

int main(void)
{
    int n, m, k;
    int remains, NumOfTeams;

    scanf("%d %d %d", &n, &m, &k);

    NumOfTeams = (n / 2 >= m) ? m : n / 2;
    remains = n + m - NumOfTeams * 3;

    while (remains < k)
    {
        NumOfTeams--;
        remains += 3;
    }
    
    printf("%d", NumOfTeams);

    return 0;
}