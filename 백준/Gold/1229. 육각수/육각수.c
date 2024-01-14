#include <stdio.h>

int hexn(int n)
{
    return 2 * n * n - n;
}

int main(void)
{
    int result, n;
    int i, j, k, l, m;
    scanf("%d", &n);

    for (i = 0; hexn(i) <= n; i++) {
        if (hexn(i) == n) {
            printf("1");
            return 0;
        }
    }

    for (i = 0; hexn(i) < n; i++) {
        for (j = i; hexn(j) < n; j++) {
            if (hexn(i) + hexn(j) == n) {
                printf("2");
                return 0;
            }
        }
    }

    if (n > 146858) {
        printf("3");
        return 0;
    }

    for (i = 0; hexn(i) < n; i++) {
        for (j = i; hexn(j) < n; j++) {
            for (k = j; hexn(k) < n; k++) {
                if (hexn(i) + hexn(j) + hexn(k) == n) {
                    printf("3");
                    return 0;
                }
            }
        }
    }

    if (n > 1791) {
        printf("4");
        return 0;
    }

    for (i = 0; hexn(i) < n; i++) {
        for (j = i; hexn(j) < n; j++) {
            for (k = j; hexn(k) < n; k++) {
                for (l = k; hexn(l) < n; l++) {
                    if (hexn(i) + hexn(j) + hexn(k) + hexn(l)== n) {
                        printf("4");
                        return 0;
                    }
                }
            }
        }
    }

    if (n > 130) {
        printf("5");
        return 0;
    }

    for (i = 0; hexn(i) < n; i++) {
        for (j = i; hexn(j) < n; j++) {
            for (k = j; hexn(k) < n; k++) {
                for (l = k; hexn(l) < n; l++) {
                    for (m = l; hexn(m) < n; m++) {
                        if (hexn(i) + hexn(j) + hexn(k) + hexn(l) + hexn(m) == n) {
                            printf("5");
                            return 0;
                        }
                    }
                }
            }
        }
    }

    if (n == 11 || n == 26) {
        printf("6");
        return 0;
    }

    return 0;
}