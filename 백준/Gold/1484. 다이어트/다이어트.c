#include <stdio.h>

int main(void)
{
    int i = 1, j = 1, g, isprint = 0;
    long long tmp;
    scanf("%d", &g);

    while (i <= 100000)
    {
        tmp = i * i - j * j;
        if (tmp > g) j++;
        else
        {
            if(tmp == g)
            {
                printf("%d\n", i);
                isprint = 1;
            }
            i++;
        }
    }

    if(isprint == 0) printf("-1");
    return 0;
}