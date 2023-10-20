#include <stdio.h>

int main(void)
{
    int i, n, a, b;
    scanf("%d", &n);
    int ary[n+1];

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        a %= 10;

        if (a == 1 || a == 5 || a == 6)
        {
            ary[i] = a;
        }
        else if (a == 4 || a == 9)
        {
            b = b % 2;
            if (b == 0) ary[i] = a * a % 10;
            else ary[i] = a;
        }
        else if (a == 2 || a == 3 || a == 7 || a == 8)
        {
            b = b % 4;
            if (b == 0) ary[i] = a * a * a * a % 10;
            else if (b == 1) ary[i] = a;
            else if (b == 2) ary[i] = a * a % 10;
            else ary[i] = a * a * a % 10;
        }
        else    // 0인 경우
        {
            ary[i] = 10;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d\n", ary[i]);
    }
    
    return 0;
}