#include <stdio.h>

int main(void)
{
    int n, m, i, sqnum;         // n, m, 반복문에 쓸 i와, 완전제곱수들을 구할 sqnum 총 4개의 int형 변수 선언
    int min = 0, sum = 0;       // 최솟값을 담을 min, 합을 담을 sum 총 2개의 int형 변수 선언 및 0으로 초기화

    scanf("%d %d", &m, &n);

    for (i = 100; i >= 1; i--)  // 100부터 1까지
    {
        sqnum = i * i;  // 완전제곱수를 구함

        if (sqnum >= m && sqnum <= n)   // if m이상, n이하의 완전제곱수이면
        {
            min = sqnum;    // m이상, n이하의 완전제곱수들 중 최솟값
            sum += sqnum;   // m이상, n이하의 완전제곱수들의 합
        }
    }

    if (sum == 0) printf("-1");         // 완전제곱수들의 합이 0이면 -1 출력
    else printf("%d\n%d", sum, min);    // 그게 아니면 합과 최솟값 출력

    return 0;
}