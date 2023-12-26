#include <stdio.h>
#include <math.h>

int main(void)
{
    int d, h, w;
    double x, rh, rw;
    scanf("%d %d %d", &d, &h, &w);
    x = d / sqrt(h * h + w * w);
    rh = h * x;
    rw = w * x;
    printf("%d %d", (int)(rh), (int)(rw));
    return 0;
}