#include <stdio.h>
#include <math.h>

int main(void)
{
    double w, h, l, rw, rh;
    scanf("%lf %lf", &w, &h);

    l = (w*w + h*h - w*sqrt(w*w+h*h)) / h;
    rw = sqrt((h-l) * (h-l) + w * w) / 2.0;
    rh = (w * l) / (2 * rw);
    
    printf("%.2lf %.2lf", rw, rh);
    return 0;
}