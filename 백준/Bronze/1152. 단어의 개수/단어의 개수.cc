#include <iostream>

int main(void)
{
    int result = 0;
    bool isword = false;
    char buf;
    
    buf = std::cin.get();
    while (buf != '\n') {
        if (buf == ' ' && isword == true) {
            result++;
            isword = false;
        }
        else if (buf != ' ' && isword == false) isword = true;
        buf = std::cin.get();
    }
    if (isword == true) result++;
    
    std::cout << result;

    return 0;
}