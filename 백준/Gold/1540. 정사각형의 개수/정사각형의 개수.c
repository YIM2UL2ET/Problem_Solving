#include <stdio.h>

int main(void)
{
    int i = 0, j = 1, dotNum, sum = 0, isAddIt = 0, n = 1;
    scanf("%d", &dotNum);

    if (dotNum < 4)
    {
        printf("0");
        return 0;
    }

    for (i = 4; i+n <= dotNum; i++)
    {
        sum += n * (n+1) / 2;
        i += n;

        if (isAddIt == 0) isAddIt = 1;
        else
        {
            isAddIt = 0;
            n++;
        }
    }

    for (i = i; i <= dotNum; i++)
    {
        sum += j;
        j++;
    }
    
    printf("%d", sum);
    return 0;
}