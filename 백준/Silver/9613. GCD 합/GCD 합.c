#include <stdio.h>

int gcd(int n1, int n2);
long long gcdSum(void);

int main(void)
{
    int i, n;
    long long result;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        result = gcdSum();
        printf("%lld\n", result);
    }
    return 0;
}

long long gcdSum(void)
{
    int i, j, n;
    long long sum = 0;
    scanf("%d", &n);
    int ary[n]; // 수의 개수만큼 배열 선언

    for (i = 0; i < n; i++) // 배열 입력
    {
        scanf("%d", &ary[i]);
    }

    for (i = 0; i < n; i++) // 각 숫자들이 모두 한번씩을 쌍을 이루어 보도록 함
    {
        for (j = i+1; j < n; j++)
        {
            sum += gcd(ary[i], ary[j]); // 각 쌍들의 gcd를 구하여 누적
        }
    }

    return sum;
}

int gcd(int n1, int n2)
{
    int tNum;       // 임시 저장 변수

    if (n1 < n2)    // n1 > n2 이도록 변경
    {
        tNum = n1;
        n1 = n2;
        n2 = tNum;
    }

    while (n2 != 0) // 유클리드 호재법 사용하여 최대공약수 구하기
    {
        tNum = n1;
        n1 = n2;
        n2 = tNum % n2;
    }

    return n1;
}