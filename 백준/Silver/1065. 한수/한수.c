#include <stdio.h>

int isEquivalentSequence(int n);

int main(void)
{
    int i, n, result = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        if(isEquivalentSequence(i)) result++;
    }
    printf("%d", result);
    return 0;
}

int isEquivalentSequence(int n) // (n <= 1000) 일때만 구분 가능
{
    if (n < 100) return 1;
    else if ((n / 100) - (n / 10 % 10) == (n / 10 % 10) - (n % 10)) return 1;
    else return 0;
}