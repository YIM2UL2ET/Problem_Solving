#include <iostream>
#include <stack>

int main(void)
{
    int n, res = 0;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::string str;
        std::stack <char> stk;
        std::cin >> str;
        
        stk.push(str[0]);
        for (int idx = 1; idx < str.size(); idx++) {
            if (!stk.empty() && stk.top() == str[idx]) stk.pop();
            else stk.push(str[idx]);
        }
        if (stk.empty()) res++;
    }
    
    std::cout << res;
    return 0;
}