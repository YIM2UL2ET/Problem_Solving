#include <stdio.h>

int main(void)
{
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // 월별 날짜수를 저장한 배열
    char days[][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}; // 요일별 문자열을 저장한 배열
    int x, y, i, j; // x, y : 월, 일 입력받을 변수 / i : for문 변수 / j : 요일 배열을 출력할 변수
    int sum = 0;    // sum: 날짜의 총 합을 저장할 변수

    scanf("%d %d", &x, &y);     // 월과 일 입력
    for (i = 0; i < x-1; i++)   // 전월 날짜의 총합을 구함
    {
        sum += months[i];
    }
    sum += y;       // 전월 날짜의 총합에 이번달 날짜를 더함
    j = sum % 7;    // 요일을 구하기 위해 7로 나눈 나머지를 변수 j에 저장

    printf("%s", days[j]);  // 요일 출력
    
    return 0;
}