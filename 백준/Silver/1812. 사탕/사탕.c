#include <stdio.h>

int main(void)
{
    int i, n;
    double tmp = 0;
    scanf("%d", &n);
    int ary[n], result[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ary[i]);
    }

    for (i = 0; i < n; i++)
    {
        if(i % 2 == 0) tmp += (ary[i] / 2.0);
        else tmp += (ary[i] * (-1) / 2.0); 
    }

    for (i = 0; i < n; i++)
    {
        printf("%.0lf\n", tmp);
        tmp = tmp * (-1) + ary[i];
    }

    return 0;
}