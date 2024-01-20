#include <iostream>
#include <algorithm>

int comp(const void * first, const void * secend);

int main(void)
{
    int n, m, total, val, temp;
    std::cin >> n >> m;
    int array[m];
    for (int i = 0; i < m; i++) {
        std::cin >> array[i];
    }
    
    qsort(array, m, sizeof(int), comp);

    total = 0;
    for (int i = 0; i < m; i++) {
        if (m - i > n) temp = array[i] * n;
        else temp = array[i] * (m - i);  // if (array[i] == array[i-1]) : always ((total > val) == true)

        if (total < temp) {
            val = array[i];
            total = temp;
        }
    }
    
    std::cout << val << std::endl << total;
    return 0;
}

int comp(const void * first, const void * secend)
{
    if (*(int*)first > *(int*)secend) return 1;
    else if (*(int*)first < *(int*)secend) return -1;
    else return 0;
}