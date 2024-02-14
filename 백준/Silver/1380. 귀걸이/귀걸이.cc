#include <iostream>
#include <string>

int main(void)
{
    int n, cnt;

    cnt = 0;
    std::cin >> n;
    getchar();
    while (n != 0) {
        cnt++;

        char ary[n] = {'1'};
        int index, result;
        std::string str[n];

        for (int i = 0; i < n; i++) {
            getline(std::cin, str[i]);
        }
        
        for (int i = 0; i < 2*n-1; i++) {
            std::cin >> index;
            if (ary[index-1] == '0') {
                std::cin >> ary[index-1];
                ary[index-1] = '1';
            }
            else {
                std::cin >> ary[index-1];
                ary[index-1] = '0';
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (ary[i] == '0') {
                result = i;
                break;
            }
        }

        std::cout << cnt << " " << str[result] << std::endl;
        std::cin >> n;
        getchar();
    }
    
    return 0;
}