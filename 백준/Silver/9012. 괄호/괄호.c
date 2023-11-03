#include <stdio.h>

int main(void)
{
    int answer, i, j, n;
    char ps[51];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        answer = 0;
        scanf("%s", ps);
        
        for(j = 0; j < 51; j++)
        {
            if (ps[j] == '(') answer++;
            else if (ps[j] == ')')
            {
                answer--;
                if (answer < 0) break;
            }
            else if (ps[j] == '\0') break;
        }

        if (answer == 0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}