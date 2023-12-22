#include <stdio.h>

int main(void)
{
    int i, left, right, lBeat = 0, rBeat = 0, beat;
    scanf("%d %d", &left, &right);
    char result[200] = {'\0'};
    beat = left * right;

    for (i = 0; lBeat != beat && rBeat != beat; i++)
    {
        if (rBeat + left == lBeat + right)
        {
            rBeat += left;
            lBeat += right;
            result[i] = '3';
        }
        else if (rBeat + left < lBeat + right)
        {
            rBeat += left;
            result[i] = '2';
        }
        else if (rBeat + left > lBeat + right)
        {
            lBeat += right;
            result[i] = '1';
        }
    }
    
    printf("%s", result);
    return 0;
}