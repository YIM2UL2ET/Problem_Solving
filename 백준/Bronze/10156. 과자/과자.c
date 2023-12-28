#include <stdio.h>

int main(void)
{
    int n, k, l, result;
    scanf("%d %d %d", &n, &k, &l);
    result = n * k - l;
    if (result > 0) printf("%d", result);
    else printf("0");
    return 0;
}