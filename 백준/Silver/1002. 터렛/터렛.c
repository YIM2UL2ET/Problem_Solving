#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, n, x1, y1, r1, x2, y2, r2;
    double d;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        d = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
        // d: 두 원의 중심간의 거리

        // case0. 두 원이 완전히 겹쳐질 때 (완전히 같을 때)
        if (r1 == r2 && x1 == x2 && y1 == y2)
        {
            printf("-1\n");
        }

        // case1. 두 점에서 만날 때
        // 두 반지름의 차 < d < 두 반지름의 합
        else if (abs(r1 - r2) < d && d < r1 + r2)
        {
            printf("2\n");
        }
        
        // case2. 한 점에서 접할 때
        // 두 반지름의 차 == d or 두 반지름의 합 == d
        else if (abs(r1 - r2) == d || r1 + r2 == d)
        {
            printf("1\n");
        }

        // case3. 만나지 않을 때
        // 두 반지름의 합 < d or 두 반지름의 차 > d
        else if (r1 + r2 < d || abs(r1 - r2) > d)
        {
            printf("0\n");
        }
    }

    return 0;
}