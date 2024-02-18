#include <iostream>
#include <vector>

int main(void)
{
    int k, buffer, result;
    std::vector <int> vec;

    std::cin >> k;
    for (int i = 0; i < k; i++) {
        std::cin >> buffer;
        if (buffer != 0) vec.push_back(buffer);
        else vec.pop_back();
    }

    result = 0;
    for (int i = 0; i < vec.size(); i++) {
        result += vec[i];
    }
    
    std::cout << result;
    return 0;
}