#include <iostream>

int solve(int * array, int size, int times);

int main(void)
{
    int n, s, start = 0;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    std::cin >> s;

    while (s > 0) {
        int i, use_time;
        
        if (s > n) i = n - 1;
        else i = s;

        for (i; i > 0; i--) {
            use_time = solve(array, n, i);
            if (use_time != 0) break;
        }

        if (i != 0) s -= use_time;
        else break;
    }

    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    
    return 0;
}

int solve(int * array, int size, int available_num)
{
    int i, j, max, index, num_of_use;

    for (i = 0; i < size-available_num; i++) {
        
        max = 0;
        for (j = i; j <= i+available_num; j++) {
            if (max < array[j]) {
                max = array[j];
                index = j;
            }
        }

        if (i != index) {
            for (int j = index; j > i; j--) {
                array[j] = array[j-1];
            }
            array[i] = max;
            num_of_use = index - i;
            return num_of_use;
        }
    }
    return 0;
}