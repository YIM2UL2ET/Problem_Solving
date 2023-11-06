#include <stdio.h>

int main(void)
{
    int stR, deX, inT, luK, sum, n, answer = 0;
    scanf("%d %d %d %d %d", &stR, &deX, &inT, &luK, &n);
    sum = stR + deX + inT + luK;
    while (sum / 4.0 < n)
    {
        sum++;
        answer++;
    }
    printf("%d", answer);
    return 0;
}