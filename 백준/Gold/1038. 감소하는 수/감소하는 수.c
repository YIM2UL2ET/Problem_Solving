#include <stdio.h>
#include <math.h>

int decreaseNum(int n);

int main(void)
{
    int j, n, result = 0, tmp;
    long long i = 0;
    scanf("%d", &n);
    
    if (n > 1022) printf("-1");
    else if (n == 1022) printf("9876543210");
    else
    {
            while(result <= n && i <= 987654321)
        {
            tmp = decreaseNum(i);
            if (tmp == 0) 
            {
                result++;
                i++;
            }
            else
            {
                i /= (int)(pow(10, tmp));
                i++;
                i *= (int)(pow(10, tmp));
            }
        }

        printf("%lld", i-1);
    }
    return 0;
}

int decreaseNum(int n)
{
    int i = 0;
    while (n > 9)
    {
        if(n % 10 >= (n / 10) % 10)
        {
            n += 10;
            i++;
        }
        n /= 10;
    }
    return i;
}