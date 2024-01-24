#include <iostream>

int main(void)
{
    int odd, size;
    int alpha[26] = {0};
    std::string str;

    std::cin >> str;
    odd = 0, size = str.size();

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < size; j++) {
            if (str[j] == 'A' + i) alpha[i]++;
        }
        if (alpha[i] % 2 == 1) odd++;
    }

    if (odd > 1 || (odd == 1 && size % 2 == 0)) std::cout << "I'm Sorry Hansoo";
    else {
        int i = 0, j = 0;
        while (i < 26) {
            if (alpha[i] == 0) i++;
            else if (alpha[i] % 2 == 1) {
                str[size / 2] = 'A' + i;
                alpha[i]--;
            }
            else {
                alpha[i] -= 2;
                str[j] = 'A' + i;
                str[size-j-1] = 'A' + i;
                j++;
            }
        }
        std::cout << str;
    }

    return 0;
}