#include <iostream>

int main(void)
{
    std::string word;
    int ary[26] = {0};
    int max = 0, index = 0;
    bool is = false;

    std::cin >> word;
    for (int i = 0; i < word.size(); i++) {
        int temp_index = toupper(word[i]) - 65;
        ary[temp_index]++;

        if (max < ary[temp_index]) {
            max = ary[temp_index];
            index = temp_index;
            is = false;
        }
        else if (max == ary[temp_index]) is = true;
    }

    if (is == true) std::cout << "?";
    else std::cout.put(index + 65);
    
    return 0;
}