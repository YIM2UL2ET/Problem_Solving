#include <stdio.h>

int main(void)
{
    int i, n, min = 5, index, score;
    scanf("%d", &n);
    char ary[n][11];
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", ary[i], &score);
        if (score < min)
        {
            min = score;
            index = i;
        }
    }
    printf("%s", ary[index]);
    return 0;
}