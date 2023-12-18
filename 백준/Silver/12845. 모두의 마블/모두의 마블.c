#include <stdio.h>

int main(void)
{
    int i, n, maxIndex, max = 0, totalGold = 0;
    scanf("%d", &n);
    int cards[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &cards[i]);
        if(cards[i] > max)
        {
            max = cards[i];
            maxIndex = i;
        }
    }

    for (i = 0; i < n; i++)
    {
        if(i != maxIndex)
        {
            totalGold += max + cards[i];
        }
    }

    printf("%d", totalGold);
    return 0;
}