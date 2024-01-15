#include <stdio.h>

int main(void)
{
    unsigned long long result = 1;
    int i, j, s, k, q, r;
    scanf("%d %d", &s, &k);

    q = s / k;
    r = s % k;  
    for (i = 0; i < k-r; i++) result *= q;
    q++;
    for (i = 0; i < r; i++) result *= q;

    if (result > 9223372036854775807) printf("9223372036854775807");
    else printf("%llu", result);
    return 0;
}