#include <stdio.h>

int main(void)
{
    int i, n, a, tmp;
    double min, max, maxtmp, mintmp;

    scanf("%d %d", &n, &a);
    if(n == 0) {
        printf("0.0");
        return 0;
    }

    int s[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &tmp);
        s[i] = tmp - a;
    }

    
    min = s[0] / 1.0;
    max = (s[0]+1) / 1.0;
    for (i = 1; i < n; i++)
    {
        mintmp = s[i] / (double)(i+1);
        maxtmp = (s[i]+1) / (double)(i+1);
        if(maxtmp < max) max = maxtmp;
        if(mintmp > min) min = mintmp;
        if(min >= max) {
            printf("-1");
            return 0;
        }
    }
    
    if(min < 0) printf("-1");
    else printf("%.9lf", min);
    return 0;
}