#include <stdio.h>
int main(void)
{
    int i, n, want, sum = 0;
    char seat[100] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &want);
        if (seat[want-1] != 0) sum++;
        else seat[want-1] = 1;
    }
    printf("%d", sum);
    return 0;
}