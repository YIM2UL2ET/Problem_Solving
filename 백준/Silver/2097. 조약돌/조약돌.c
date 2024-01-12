#include <stdio.h>

int main(void)
{
    int n, i = 1, cnt = 1, os = 1, result = 0;
    scanf("%d", &n);

    if(n < 4) {
        printf("4");
        return 0;
    }
    
    while (cnt < n) {
        cnt += i;
        result += 2;
        if(os == 1) {
            os = 0;
            i++;
        }
        else os = 1;
    }
    
    printf("%d", result);
    return 0;
}