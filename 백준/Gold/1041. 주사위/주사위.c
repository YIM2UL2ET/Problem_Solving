#include <stdio.h>

int Find1SideMinValue(int *ary);
int Find2SideMinValue(int *ary);
int Find3SideMinValue(int *ary);

int main(void)
{
    long long result = 0;
    int n, i;
    int dice[6];

    scanf("%d", &n);
    for (i = 0; i < 6; i++)
    {
        scanf("%d", &dice[i]);
    }

    if (n > 1)
    {
        long long min1side, min2side, min3side;

        min1side = Find1SideMinValue(dice);
        min2side = Find2SideMinValue(dice);
        min3side = Find3SideMinValue(dice);
        
        //  result += min1side * (4(n-1)(n-2) + (n-2)^2);
        result += min1side * 5;
        result *= n;
        result *= n;
        result -= min1side * (16 * n);
        result += min1side * 12;

        //  result += min2side * (4(n-1) + 4(n-2))
        result += min2side * (2 * n - 3) * 4;

        result += min3side * 4;
    }
    else
    {
        int max = 0;
        for (i = 0; i < 6; i++)
        {
            result += dice[i];
            if (max < dice[i]) max = dice[i];
        }
        result -= max;
    }
    
    printf("%lld", result);
    return 0;
}

int Find1SideMinValue(int *ary)
{
    int i, result = ary[0];
    for (i = 1; i < 6; i++)
    {
        if (result > ary[i]) result = ary[i];
    }
    return result;
}

int Find2SideMinValue(int *ary)
{
    int i, j, result = ary[0] + ary[1];

    for (i = 0; i < 6; i++)
    {
        for (j = i+1; j < 6; j++)
        {
            if(i + j == 5) continue;
            if(result > ary[i] + ary[j]) result = ary[i] + ary[j];
        }
    }
    return result;
}

int Find3SideMinValue(int *ary)
{
    int result;

    result = ary[2] + ary[0] + ary[4];
    if (result > ary[2] + ary[0] + ary[1]) result = ary[2] + ary[0] + ary[1];
    if (result > ary[2] + ary[5] + ary[1]) result = ary[2] + ary[5] + ary[1];
    if (result > ary[2] + ary[5] + ary[4]) result = ary[2] + ary[5] + ary[4];
    if (result > ary[3] + ary[0] + ary[4]) result = ary[3] + ary[0] + ary[4];
    if (result > ary[3] + ary[0] + ary[1]) result = ary[3] + ary[0] + ary[1];
    if (result > ary[3] + ary[5] + ary[1]) result = ary[3] + ary[5] + ary[1];
    if (result > ary[3] + ary[5] + ary[4]) result = ary[3] + ary[5] + ary[4];
    return result;
}