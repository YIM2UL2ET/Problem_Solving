#include <stdio.h>

int main(void)
{
    int i, n, k, t, max, result;
    long long tmp;
    scanf("%d %d", &n, &k);
    
    max = 0; tmp = 9;
    for (i = 1; n - tmp >= 0; i++) {
        max += tmp * i;
        n -= tmp;
        tmp *= 10;
    }
    max += n * i;

    if (max < k) {
        printf("-1");
        return 0;
    }

    tmp = 9;
    for (i = 1; k - tmp * i > 0; i++) {
        k -= tmp * i;
        tmp *= 10;
    }

    if (i == 1) tmp = 0;
    else {
        tmp = 1;
        for (int j = 1; j < i; j++) tmp *= 10;
    }
    result = (((k - (k-1) % i) / i) + tmp);

    tmp = 1; t = i - (k-1) % i;
    for (int j = 1; j < t; j++) tmp *= 10;
    result = result / tmp % 10;
    
    printf("%d", result);
    return 0;
}