#include <stdio.h>

int main(void)
{
    int i, j, n, size, _n = 0, n_ = 1000, result = 0;
    scanf("%d", &size);
    int collection[size];
    for (i = 0; i < size; i++)
    {
        scanf("%d", &collection[i]);
    }
    scanf("%d", &n);

    for (i = 0; i < size; i++)
    {
        if(collection[i] < n &&  collection[i] > _n) _n = collection[i];
        else if(collection[i] > n && collection[i] < n_) n_ = collection[i];
        else if (collection[i] == n)
        {
            printf("0");
            return 0;
        }
    }

    for (i = _n+1; i <= n; i++)
    {
        for (j = n; j <= n_-1; j++)
        {
            if(i != j) result++;
        }
    }
    
    printf("%d", result);
    return 0;
}