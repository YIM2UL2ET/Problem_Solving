#include <stdio.h>

int main(void)
{
    int i, ball, basket;
    scanf("%d %d", &ball, &basket);
    
    // 공을 바구니에 1부터 공차가 1인 등차수열대로 담기
    for (i = 1; i <= basket; i++)
    {
        ball -= i;
    }
    i--;

    // 개수대로 맞게 들어가면 최대(i) - 최소(1) 출력
    if (ball == 0)
    {
        printf("%d", i - 1);
    }

    // 공이 바구니에 나눠담기에 모자라면 -1 출력
    else if (ball < 0)
    {
        printf("-1");
    }

    // 남은 공이 있으면 남은 공을 바구니에 나눠담은 후 출력
    else
    {
        if (ball % basket == 0) printf("%d", i - 1);
        else printf("%d", i);
    }

    return 0;
}