#include <stdio.h>

int gcd(int n1, int n2);    // 최대공약수 구하는 함수
int lcm(int n1, int n2);    // 최소공배수 구하는 함수

int main(void)
{
    int num1, num2, den1, den2, numA, denA, gcdNum;
    scanf("%d %d %d %d", &num1, &den1, &num2, &den2);

    denA = lcm(den1, den2); // 분모A == 분모1과 분모2의 최소공배수
    numA = denA / den1 * num1 + denA / den2 * num2; //분자A == 분모1과 분모2를 분모A로 통분한 후 분자들을 더한 것

    gcdNum = gcd(denA, numA);       // 분자A와 분모A의 최대공약수(gcdNum)를 구함
    denA /= gcdNum;                 // 분자A와 분모A를 gcdNum으로 나눔
    numA /= gcdNum;
    printf("%d %d", numA, denA);    // 분자A와 분모A 출력
    return 0;
}

int gcd(int n1, int n2) // 최대공약수를 구하는 함수
{
    int temNum;         // 임시 변수

    if (n1 < n2)        // n1 > n2 로 만드는 작업
    {
        temNum = n1;
        n1 = n2;
        n2 = temNum;
    }

    while (n2 != 0)     // n2가 0이 아닐때 까지 유클리드 호재법을 사용
    {
        temNum = n1;
        n1 = n2;
        n2 = temNum % n1;
    }
    
    return n1;          // n2가 0이되면 n1 return
}

int lcm(int n1, int n2)     // 최소공배수를 구하는 함수
{
    int n = gcd(n1, n2);    // 최대공약수를 먼저 구함
    return n1 * n2 / n;     // n1과 n2를 곱한 후 최대공약수를 나눠 return
}