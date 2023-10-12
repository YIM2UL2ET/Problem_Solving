#include <stdio.h>

int main(void)
{
    int x, y, w, h, min;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    min = (x < w - x) ? x : w - x;
    min = (min < y) ? min : y;
    min = (min < h - y) ? min : h - y;
    printf("%d", min);

    return 0;
}