#include <iostream>
#include <algorithm>
#include <vector>

bool fMax(std::string max, std::string val) {
    if (max.size() != val.size()) return max.size() < val.size();
    return max < val;
}

bool comp(std::string str1, std::string str2) {
    return str1 + str2 > str2 + str1;
}

int main(void) {
    int k, n;
    std::string max;
    std::cin >> k >> n;

    std::vector <std::string> vec(n);
    for (int i = 0; i < k; i++) {
        std::cin >> vec[i];
        if (fMax(max, vec[i])) max = vec[i];
    }
    for (int i = k; i < n; i++) vec[i] = max;
    
    std::sort(vec.begin(), vec.end(), comp);
    for (std::string digit : vec) std::cout << digit;
    return 0;
}