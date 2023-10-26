#include <stdio.h>

int main(void)
{
    int n, i, oldest = 0, youngest = 0;
    scanf("%d", &n);        // 사람이 몇명인지 입력

    char names[n+1][16];    // n+1 만큼의 크기로 배열 선언
    int years[n+1];
    int months[n+1];
    int days[n+1];

    for (i = 0; i < n; i++) // n명만큼 이름, 생일, 생월, 생년 입력받기
    {
        scanf("%s %d %d %d", &names[i], &days[i], &months[i], &years[i]);
    }

    for (i = 0; i < n; i++) // 나이가 제일 어린사람 찾기 찾기
    {
        if (years[i] > years[youngest]){
            youngest = i;
            continue;
        }
        else if (years[i] == years[youngest]){
            if (months[i] > months[youngest]){
                youngest = i;
                continue;
            }
            else if (months[i] == months[youngest]){
                youngest = days[youngest] > days[i] ? youngest : i;
            }
        }
    }

    for (i = 0; i < n; i++) // 나이가 제일 많은사람 찾기
    {
        if (years[i] < years[oldest]){
            oldest = i;
            continue;
        }
        else if (years[i] == years[oldest]){
            if (months[i] < months[oldest]){
                oldest = i;
                continue;
            }
            else if (months[i] == months[oldest]){
                oldest = days[oldest] < days[i] ? oldest : i;
            }
        }
    }

    printf("%s\n%s", names[youngest], names[oldest]);
    return 0;
}