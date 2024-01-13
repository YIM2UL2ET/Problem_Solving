#include <stdio.h>

int main(void)
{
    int i, n, index, max, r;
    scanf("%d", &n);

    int ary[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    max = 0; r = 0;
    while (1) {
        for (i = 1; i < n; i++) {
            if (max < ary[i]) {
                max = ary[i];
                index = i;
            }
        }
        
        if (ary[0] > max) break;

        ary[index]--;
        ary[0]++;
        max--;
        r++;
    }

    printf("%d", r);
    return 0;
}