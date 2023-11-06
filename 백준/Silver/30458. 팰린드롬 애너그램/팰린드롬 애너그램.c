#include <stdio.h>

int main(void)
{
    int n, i, j, count;
    scanf("%d", &n);

    char ary[n];
    scanf("%s", &ary);

    for (i = 97; i < 123; i++)
    {
        count = 0;

        for (j = 0; j < n; j++)
        {
            if (ary[j] == i) count++;
        }

        if (count % 2 == 1)
        {
            if (ary[n / 2] == i) continue;
            printf("No");
            return 0;
        }
        
    }

    printf("Yes");
    return 0;
}