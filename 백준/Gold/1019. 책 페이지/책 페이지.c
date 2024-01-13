#include <stdio.h>

int main(void)
{
    int i, j, q, r, cnt;
    long long n, s, d, temp;
    long long ary[10] = {0};

    scanf("%lld", &n);

    // count 횟수 설정
    cnt = 1; temp = 10;
    while (temp <= n) {
        temp *= 10;
        cnt++;
    }

    // 구하는 과정
    d = 10; s = 0;
    for (i = 0; i < cnt; i++) {
        q = (n - s) / d;
        r = (n - s) % d;

        // quotient의 경우 (자릿수별 숫자 순환 횟수)
        for (j = 0; j < 10; j++) {
            ary[j] += q * (d/10);
        }
        
        // remainder의 경우 (quotient을 제외한 남은 자릿수별 숫자 처리)
        temp = r / (d/10);
        j = 1;
        while (temp > 0) {
            ary[j++] += (d/10);
            if (j == 10) j = 0;
            temp--;
        }
        ary[j] += r % (d/10);

        // 증가처리 subtrahend : 0, 9, 99, 999 ... divisor: 10, 100, 1000 ...
        s *= 10; s += 9;
        d *= 10;
    }
    
    // 출력
    for (i = 0; i < 10; i++) {
        printf("%lld ", ary[i]);
    }
    
    return 0;
}