#include <stdio.h>
#include <string.h>
#include <math.h>

int changeRnumToAnum(char* Rnum, int len);
int changeRtoA(char n);
void printfAnumtoRnum(int n);

int main(void)
{
    int i, alen, blen, sum;
    int aAnum = 0, bAnum = 0;
    char aRNum[20], bRNum[20];

    scanf("%s", aRNum);
    scanf("%s", bRNum);

    alen = strlen(aRNum);
    blen = strlen(bRNum);

    aAnum = changeRnumToAnum(aRNum, alen);
    bAnum = changeRnumToAnum(bRNum, blen);
    sum = aAnum + bAnum;

    printf("%d\n", sum);
    printfAnumtoRnum(sum);
    return 0;
}

int changeRnumToAnum(char* Rnum, int len)
{
    int i, tmp, result = 0;
    for (i = 0; i < len; i++)
    {
        tmp = changeRtoA(Rnum[i]);
        if (result % 10 == 1 && result % 10 < tmp) result += (tmp - 2);
        else if (result % 100 == 10 && result % 100 < tmp) result += (tmp - 20);
        else if (result % 1000 == 100 && result % 1000 < tmp) result += (tmp - 200);
        else result += tmp;
    }
    return result;
}

int changeRtoA(char n)
{
    switch (n)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        printf("ERROR");
        return 0;
    }
}

void printfAnumtoRnum(int n)
{
    int i, rank, tmp = n;
    char one, five, ten;
    for (rank = 0; tmp > 0; rank++) tmp /= 10;
    for (i = rank; i > 0; i--)
    {
        tmp = n / (int)pow(10,i-1) % 10;
        switch (i)
        {
        case 1:
            one = 'I';
            five = 'V';
            ten = 'X';
            break;
        case 2:
            one = 'X';
            five = 'L';
            ten = 'C';
            break;
        case 3:
            one = 'C';
            five = 'D';
            ten = 'M';
            break;
        case 4:
            one = 'M';
            break;
        }

        switch (tmp)
        {
        case 0:
            break;
        case 1:
            printf("%c", one); 
            break;
        case 2:
            printf("%c%c", one, one); 
            break;
        case 3:
            printf("%c%c%c", one, one, one); 
            break;
        case 4:
            printf("%c%c", one,five); 
            break;
        case 5:
            printf("%c", five); 
            break;
        case 6:
            printf("%c%c", five, one); 
            break;
        case 7:
            printf("%c%c%c", five, one, one); 
            break;
        case 8:
            printf("%c%c%c%c", five, one, one, one); 
            break;
        case 9:
            printf("%c%c", one, ten); 
            break;
        }
    }
    return;
}