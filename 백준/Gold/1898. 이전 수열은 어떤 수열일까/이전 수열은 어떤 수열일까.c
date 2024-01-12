#include <stdio.h>

int main(void)
{
    int i, j, n, index, o = 1;
    scanf("%d", &n);
    int ary[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
        if (ary[i] == n) index = i;
    }

    for (i = n; i > 0; i--) {
        for (j = 0; i != ary[j]; j++) {}
        if (o == 1 && index < j) {
            ary[j] = ary[index];
            ary[index] = i;
            o = 0;
        }
        else if (o == 0) o = 1;
        index = j;
    }

    for (i = 0; i < n; i++) printf("%d\n", ary[i]);
    
    return 0;
}