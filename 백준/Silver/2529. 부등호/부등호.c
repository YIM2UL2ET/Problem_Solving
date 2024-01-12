#include <stdio.h>

int main(void)
{
    int i, j, n, index;
    scanf("%d", &n);  
    char maxn = '9', minn = '0';
    char ary[n], max[11] = {'\0'}, min[11] = {'\0'};
    for (i = 0; i < n; i++) scanf(" %c", &ary[i]);

    max[0] = '9';
    min[0] = '0';

    index = 0;
    for (i = 1; i <= n; i++) {
        if(ary[i-1] == '<') {
            max[i] = max[i-1];
            for (j = index; j < i; j++) max[j]--;
        }
        else {
            index = i;
            max[i] = maxn - 1;
        }
        maxn--;
    }

    index = 0;
    for (i = 1; i <= n; i++) {
        if(ary[i-1] == '>') {
            min[i] = min[i-1];
            for (j = index; j < i; j++) min[j]++;
        }
        else {
            index = i;
            min[i] = minn + 1;
        }
        minn++;
    }
    
    printf("%s\n%s", max, min);
    return 0;
}