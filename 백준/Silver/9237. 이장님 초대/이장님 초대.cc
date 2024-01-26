#include <iostream>
#include <algorithm>

int comp(const void * first, const void * secend);

int main(void)
{
    int n, result = 0;
    std::cin >> n;
    int ary[n];

    for (int i = 0; i < n; i++) std::cin >> ary[i];
    qsort(ary, n, sizeof(int), comp);

    for (int i = 0; i < n; i++) {
        if (result < ary[i] + i + 2) result = ary[i] + i + 2;
    }
    
    std::cout << result;
    return 0;
}

int comp(const void * first, const void * secend)
{
    if (*(int*)first > *(int*)secend) return -1;
    else if (*(int*)first < *(int*)secend) return 1;
    else return 0;
}