#include <stdio.h>

int main(void)
{
    int x, y, sum;
    scanf("%d %d", &x, &y);
    if (x > y) sum = x + (y / 10) + y;
    else sum = x + (x / 10) + y;
    printf("%d", sum);
    return 0;
}