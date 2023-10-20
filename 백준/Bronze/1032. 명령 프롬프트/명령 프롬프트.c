#include <stdio.h>

int main(void)
{
    int count, i, j;              // 파일의 개수 count, 2개의 for문에 사용할 i, j 변수

    scanf("%d", &count);
    char file_name[51], search_name[51];    // 최대 50글자의 파일명을 저장할 변수와, 검색어를 저장할 변수 선언

    scanf("%s", search_name);               // 첫번째로 입력받은 파일명을 검색어에 저장
    count--;                                // 파일을 한번 적었으므로 count -=1

    for (i = 0; i < count; i++)             // count만큼 파일명을 더 입력
    {
        scanf("%s", file_name);

        for (j = 0; j < 51; j++)                    // 배열의 크기 (51) 만큼 카운트
        {
            if (search_name[j] == '\0')             // 배열의 구성요소가 널값이면 끝내기
            {
                break;
            }
            if (search_name[j] != file_name[j])     // 검색어와 파일명의 글자 비교
            {
                search_name[j] = '?';               // 다르면 검색어를 ?로 변경
            }
        }
    }

    printf("%s", search_name);
    
    return 0;
}