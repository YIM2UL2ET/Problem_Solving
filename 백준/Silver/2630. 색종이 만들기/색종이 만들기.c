#include <stdio.h>

static int one, zero;

void FindSquareNum(int size, int xIndex, int yIndex, int (*pary)[129]);

int main(void)
{
    int i, j, n;
    scanf("%d", &n);

    int ary[129][129] = {'\0'};
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &ary[i][j]);
        }
    }

    FindSquareNum(n, 0, 0, ary);
    printf("%d\n%d", zero, one);

    return 0;
}

void FindSquareNum(int size, int xIndex, int yIndex, int (*pary)[129])
{
    int i, j, tmp;
    tmp = pary[yIndex][xIndex];

    for (i = yIndex; i < yIndex+size; i++)
    {
        for (j = xIndex; j < xIndex+size; j++)
        {
            if (tmp != pary[i][j]) break;
        }
        if (j != xIndex+size) break;
    }
    
    if (i == yIndex+size && j == xIndex+size)
    {
        if (tmp) one++;
        else zero++;
    }
    else
    {
        tmp = size / 2;
        FindSquareNum(tmp, xIndex, yIndex, pary);
        FindSquareNum(tmp, xIndex+tmp, yIndex, pary);
        FindSquareNum(tmp, xIndex, yIndex+tmp, pary);
        FindSquareNum(tmp, xIndex+tmp, yIndex+tmp, pary);
    }
}