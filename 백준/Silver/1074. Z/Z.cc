#include <iostream>
int main(void)
{
    int n, c, r, result, size;
    std::cin >> n >> r >> c;

    size = 1;
    for (int i = 0; i < n; i++) size *= 2;

    result = 0;
    while (c != 0 || r != 0) {
        size /= 2;
        if (r < size && c >= size) {
            result += size * size * 1;
            c -= size;
        }
        else if (r >= size && c < size) {
            result += size * size * 2;
            r -= size;
        }
        else if (r >= size && c >= size) {
            result += size * size * 3;
            r -= size, c -= size;
        }
    }
    
    std::cout << result;
    return 0;
}