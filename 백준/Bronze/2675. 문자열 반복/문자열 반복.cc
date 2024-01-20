#include <iostream>
#include <string>

int main(void)
{
    int cnt, n;
    std::string buffer;
    std::cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        std::cin >> n >> buffer;
        for (int j = 0; j < buffer.size(); j++) {
            for (int k = 0; k < n; k++) {
                std::cout << buffer[j];
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}