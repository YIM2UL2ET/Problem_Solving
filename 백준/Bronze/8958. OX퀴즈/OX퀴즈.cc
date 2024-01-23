#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int result, temp;

        std::string ox;
        std::cin >> ox;

        result = 0, temp = 1;
        for (int j = 0; j < ox.size(); j++) {
            if (ox[j] == 'O') result += temp++;
            else temp = 1;
        }

        std::cout << result << std::endl;
    }
    
    return 0;
}