#include <iostream>

int FindValue(int n)
{
    int result = 1;
    for (int i = 0; i < n; i++) result *= 2;
    return --result;
}

void Hanoi(int level, int start, int between, int end)
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);

    if (level == 1) std::cout << start << " " << end << "\n";
    else {
        Hanoi(level-1, start, end, between);
        std::cout << start << " " << end << "\n";
        Hanoi(level-1, between, start, end);
    }
    return;
}

int main(void) {
    int n;
    std::cin >> n;
    std::cout << FindValue(n) << "\n";
    Hanoi(n, 1, 2, 3);
    return 0;
}