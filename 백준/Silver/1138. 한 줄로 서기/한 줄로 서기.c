#include <stdio.h>

int main(void)
{
    int i, j , frontBiggersNum, n;
    scanf("%d", &n);
    int line[n];

    for (i = 0; i < n; i++) {line[i] = '\0';}   // n개만큼 빈 자리 만들기

    for (i = 1; i <= n; i++)            // for: 키가 작은 순서대로 자리를 먼저 서게 하기
    {
        scanf("%d", &frontBiggersNum);  // 번호대로 앞에 서있어야 하는 키가 큰 사람의 수 입력

        for (j = 0; j < n; j++)         // for: 앞자리부터 보기
        {
            if (line[j] == '\0')            // 자리가 비었을 때 (1)과 (2)로 판단
            {
                if (frontBiggersNum != 0)   // if(1): 만약 내 앞에 나보다 키가 큰 사람이 서야한다면
                {
                    frontBiggersNum--;      // 자리 비우고 더 뒤로 가기
                }
                else                        // if(2): 그게 아니라면
                {
                    line[j] = i;            // 그 자리에 서고 다음사람 줄 서기
                    break;
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) {printf("%d ", line[i]);}   // 출력
    return 0;
}