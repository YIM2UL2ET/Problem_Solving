#include <stdio.h>
#include <math.h>

void InputRowAndCol(long* row, long* col);
void ChangeColToAlpha(long col, char* alpha_ary);
void cd(char* ary, int index);

int main(void)
{
    long row, col;
    char col_alpha[10];

    while(1)
    {
        InputRowAndCol(&row, &col);
        if (row == 0 && col == 0) break;
        ChangeColToAlpha(col, col_alpha);

        printf("%s%ld\n", col_alpha, row);
    }

    return 0;
}

void InputRowAndCol(long* row, long* col)
{
    getchar();
    scanf("%d", row);
    getchar();
    scanf("%d", col);
    getchar();
}

void ChangeColToAlpha(long col, char* alpha_ary)
{
    int i, j, sum;
    long tmp = 1;
    while(tmp <= col) tmp *= 26;
    tmp /= 26;
    
    for (i = 0; tmp != 0; i++)
    {
        alpha_ary[i] = col / tmp + 64;
        col %= tmp;
        tmp /= 26;
    }

    alpha_ary[i] = '\0';

    for(j = i-1; j > 0; j--)
    {
        cd(alpha_ary, j);
    }

    while(alpha_ary[0] == '@')
    {
        for (j = 0; j < i; j++)
        {
            alpha_ary[j] = alpha_ary[j+1];
        }
    }
}

void cd(char* ary, int index)
{
    if(ary[index] < 65)
    {
        ary[index-1]--;
        ary[index] += 26;
    }
}