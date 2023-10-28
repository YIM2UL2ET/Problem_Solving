#include <stdio.h>

int main(void)
{
    int n, i, ySum = 0, mSum = 0;
    scanf("%d", &n);
    int ary[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &ary[i]);
    }

    for (i = 0; i < n; i++)
    {
        ySum += (ary[i] / 30 + 1) * 10;
        mSum += (ary[i] / 60 + 1) * 15;
    }

    if (ySum < mSum) printf("Y %d", ySum);
    else if (ySum > mSum) printf("M %d", mSum);
    else printf("Y M %d", ySum);
    
    return 0;
}