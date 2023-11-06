#include <stdio.h>

int main(void)
{
    int i, j, lineMaxNum = 0, isLine = 0, lineNum = 0, sum = 0, population, length;
    scanf("%d %d", &population, &length);
    char ary[population][length];
    for (i = 0; i < population; i++)
    {
        scanf("%s", &ary[i]);
    }

    for (i = 0; i < population; i++)
    {
        isLine = 0;
        lineNum = 0;
        for (j = 0; j < length; j++)
        {
            if (ary[i][j] == '1' && isLine == 0)
            {
                lineNum++;
                isLine = 1;
            }
            else if (ary[i][j] == '0' && isLine == 1) isLine = 0;
        }

        if (lineMaxNum < lineNum)
        {
            sum = 1;
            lineMaxNum = lineNum;
        }
        else if (lineMaxNum == lineNum) sum++;
    }
    printf("%d %d", lineMaxNum, sum);
    return 0;
}