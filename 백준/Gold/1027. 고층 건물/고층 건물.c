#include <stdio.h>

int isYLessThanX(int x, int y, double m);

int countVisibleBuildings(int *ary, int index, int len);

int main(void)
{
    int i, n, count, max = 0, index = 0;
    scanf("%d", &n);
    int buildingAry[n];
    for (i = 0; i < n; i++) scanf("%d", &buildingAry[i]);
    
    for (i = 0; i < n; i++)
    {
        count = countVisibleBuildings(buildingAry, i, n);
        max = max > count ? max : count;
    }

    printf("%d", max);
    return 0;
}

int countVisibleBuildings(int *ary, int index, int len)
{
    int i, j, result = 0, istrue = 1;
    double m;

    for (i = index+1; i < len; i++)
    {
        m = (double)(ary[i] - ary[index]) / (i - index);
        for (j = index+1; j < i; j++)
        {
            if((isYLessThanX(j-index, ary[j]-ary[index], m)) == 0) istrue = 0;
        }
        if (istrue) result++;
        else istrue = 1;
    }

    for (i = index-1; i >= 0; i--)
    {
        m = (double)(ary[i] - ary[index]) / (i - index);
        for (j = index-1; j > i; j--)
        {
            if((isYLessThanX(j-index, ary[j]-ary[index], m)) == 0) istrue = 0;
        }
        if (istrue) result++;
        else istrue = 1;
    }
    
    return result;
}

int isYLessThanX(int x, int y, double m)
{
    if (y < m * x) return 1;
    else return 0;
}