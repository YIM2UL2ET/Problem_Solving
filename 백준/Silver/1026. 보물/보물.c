#include <stdio.h>

int main(void)
{
    int i, j, n, tv, s = 0, min = 100, max = 0;    // int형 변수 선언
    int aryA[51], aryB[51], aryMinA[51];
    
    /* i, j : for문에 사용할 변수 / 배열 A,B의 크기와, for문 등에 사용할 변수 / tv : 값을 임시로 저장할 변수
    s = 문제의 s / min : 배열 A의 최솟값을 구하기 위한 변수 / max : 배열 B의 최댓값을 구하기 위한 변수 */

    scanf("%d", &n);    // 배열의 크기 입력
    
    for (i = 0; i < n; i++)             // 배열 A 와 B 입력
    {
        scanf("%d", &aryA[i]);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &aryB[i]);
    }

    for (i = 0; i < n; i++)         // aryMinA 배열의 주소 [0]~[n]에 차레대로 작은수를 저장
    {
        for (j = 0; j < n; j++)
        {
            if (min > aryA[j])
            {
                tv = j;
                min = aryA[j];
            }
        }
        aryMinA[i] = min;
        aryA[tv] = 100;
        min = 100;
        tv = 0;
    }
    
    for (i = 0; i < n; i++)         // s에 차례대로 (배열 B의 큰수 * 배열 A의 작은수) 를 더해감
    {
        for (j = 0; j < n; j++)
        {
            if (max < aryB[j])
            {
                tv = j;
                max = aryB[j];
            }
        }
        s += aryMinA[i] * max;
        aryB[tv] = 0;
        max = 0;
        tv = 0;
    }
    
    printf("%d", s);                // 답 출력

    return 0;
}