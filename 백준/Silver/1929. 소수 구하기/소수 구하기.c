#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, j, n, m;
    double tmp;
    int pn[1000] = {'\0'};
    scanf("%d %d", &n, &m);

    tmp = sqrt(m);

    for (i = 2; i <= m; i++)
    {
        for (j = 0; pn[j] != '\0'; j++)
        {
            if(i % pn[j] == 0) break;
        }
        if (pn[j] == '\0') 
        {
            if(tmp >= i) pn[j] = i;
            if(n <= i) printf("%d\n", i);
        }
    }
    return 0;
}