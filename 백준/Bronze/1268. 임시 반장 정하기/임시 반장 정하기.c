#include <stdio.h>

int main(void)
{
    int n, i, j, k, max = 0, o = 0, asw = 0;
    scanf("%d", &n);
    int ary[n][5];

    // 행렬 입력
    for (i = 0; i < n; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &ary[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {           // i+1번째 학생
        for (j = 0; j < n; j++) {       // j+1번째 학생
            for (k = 0; k < 5; k++) {   // 학년
                if (ary[i][k] == ary[j][k]) {   // 같은반이면 o++, break;로 더이상 비교x
                    o++;
                    break;
                }
            }
        }
        if (max < o) {  // i+1번째 학생이 다른아이들과 같은반이 된적이 있는 인원의 수+1이 max보다 크면
            max = o;    // 최대치에 o 입력, i+1번째 학생이 반장 후보
            asw = i+1;
        }
        o = 0;          // o 초기화
    }

    printf("%d", asw);
    return 0;
}