#include <iostream>

int main(void)
{
    int n, m, cnt, apple, left, right, result;
    std::cin >> n >> m >> cnt;
    left = 1, right = m, result = 0;
    for (int i = 0; i < cnt; i++) {
        std::cin >> apple;
        while (left > apple) {
            left--;
            right--;
            result++;
        }
        while (right < apple) {
            left++;
            right++;
            result++;
        }
    }

    std::cout << result;
    return 0;
}