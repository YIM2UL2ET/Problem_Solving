#include <stdio.h>

int main(void)
{
    int i, l, r, k, result = 0;
    scanf("%d %d %d", &l, &r, &k);

    switch (k)
    {
    case 2:
        if (l < 3) {for (i = 3; i <= r; i++) result++;}
        else {for (i = l; i <= r; i++) result ++;}
        break;

    case 3:
        while (l % 3) l++;
        if (l < 6) {for (i = 6; i <= r; i+=3) result++;}
        else {for (i = l; i <= r; i+=3) result ++;}
        break;

    case 4:
        while (l % 2) l++;
        if (l < 14) {for (i = 14; i <= r; i+=2) result++;}
        else {for (i = l; i <= r; i+=2) result ++;}
        if (l <= 10 && r >= 10) result++;
        break;

    case 5:
        while (l % 5) l++;
        if (l < 15) {for (i = 15; i <= r; i+=5) result++;}
        else {for (i = l; i <= r; i+=5) result ++;}
        break;
    }

    printf("%d", result);
    return 0;
}