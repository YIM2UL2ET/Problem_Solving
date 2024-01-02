#include <stdio.h>

int FindIndex(int n, int *ary);

void ChangeValue(int xi, int yi, int *ary);

int main(void)
{
    int n, i, x, y, xi, yi;
    int ary[3] = {1, 2, 3};
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        xi = FindIndex(x, ary);
        yi = FindIndex(y, ary);
        ChangeValue (xi, yi, ary);
    }
    printf("%d", ary[0]);
    return 0;
}

int FindIndex(int n, int *ary)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if(ary[i] == n) break;
    }
    return i;
}

void ChangeValue(int xi, int yi, int *ary)
{
    int tmp = ary[xi];
    ary[xi] = ary[yi];
    ary[yi] = tmp;
}