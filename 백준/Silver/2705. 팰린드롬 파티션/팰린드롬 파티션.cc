#include <iostream>

int ary[1000] = {0};

int solve(int n)
{   
    if (n == 1) return 1;
    else if (ary[n-1] != 0) return ary[n-1];
    else {
        int temp = 1;
        for (int i = 0; n-i*2 > 1; i++) temp += solve(i+1);
        ary[n-1] = temp;
        return ary[n-1];
    }
}

int main(void)
{
    int n, input;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        std::cout << solve(input) << std::endl;
    }
    return 0;   
}