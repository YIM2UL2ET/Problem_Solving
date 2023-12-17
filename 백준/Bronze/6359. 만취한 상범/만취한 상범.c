#include <stdio.h>

int main(void)
{
    int i, j, cnt, n, sum;
    int rooms[100];

    scanf("%d", &cnt);

    for (i = 0; i < cnt; i++)
    {
        sum = 0;
        for (j = 0; j < 100; j++) rooms[j] = 1;

        scanf("%d", &n);

        for (j = 2; j <= n; j++)
        {
            int tmp = j;
            while(tmp <= n)
            {
                if(rooms[tmp-1] == 0) rooms[tmp-1] = 1;
                else if(rooms[tmp -1] == 1) rooms[tmp-1] = 0;
                tmp += j;
            }
        }

        for (j = 0; j < n; j++)
        {
            if(rooms[j] == 1) sum++;
        }
        
        printf("%d\n", sum);
    }
    return 0;
}